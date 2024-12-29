#pragma once
#include "ScreenStack.h"

//class CircularLinkedList;

class Node
{
//friend class CircularLinkedList;
public:
	ScreenStack m_stack;
	Node* m_prev;
	Node* m_next;

public:
	Node ()
	{
		m_prev = nullptr;
		m_next = nullptr;
	}
	
	Node(int x, int y)
	{
		m_stack = ScreenStack(x,y);
		m_prev = nullptr;
		m_next = nullptr;
	}

	ScreenStack getStack()
	{
		return m_stack;
	}
};

class CircularLinkedList
{
	Node* m_head;
	Node* m_current;

private:
	int PositionofCurrentNode()
	{
		if (m_head != nullptr)
		{
			Node* auxNode = m_head;
			int position = 0;

			while (auxNode != m_current)
			{
				auxNode = auxNode->m_next;
				position++;
			}
			return position;
		}
		else
			return -1;
	}

	void EraseStacks()
	{
		for (int i = PositionofCurrentNode() + 1; i < NumberofNodes(); i++)
		{
			Node* auxNode = m_current->m_next;
			
			auxNode->m_stack.DrawStack(0); //0 = black; 3 = cyan; 7 = white;
			auxNode = auxNode->m_next;
		}
	}

	void RedrawStacks()
	{
		for (int i = PositionofCurrentNode() + 1; i < NumberofNodes(); i++)
		{
			Node* auxNode = m_current->m_next;

			auxNode->m_stack.DrawStack(7); //0 = black; 3 = cyan; 7 = white;
			auxNode = auxNode->m_next;
		}
	}

public:

	CircularLinkedList()
	{
		m_head = nullptr;
		m_current = nullptr;
	}

	CircularLinkedList(int x, int y)
	{
		m_head = new Node(6, 14);
		m_head->m_prev = m_head;
		m_head->m_next = m_head;
		m_current = m_head;
	}

	int NumberofNodes()
	{
		if (m_head == nullptr)
			return 0;
		else
		{
			Node* auxNode = m_head;
			int counter = 1;

			while (m_head != auxNode->m_next && counter < 5)
			{
				auxNode = auxNode->m_next;
				counter++;
			}
			return counter;
		}			
	}

	void InsertatBeginning()
	{
		if (m_head == nullptr)
		{
			m_head = new Node(6, 14);
			m_head->m_prev = m_head;
			m_head->m_next = m_head;
			m_current = m_head;
		}
	}

	void InsertatPosition()
	{
		if (NumberofNodes() < 6)
		{
			Node* auxNode = new Node(m_current->m_stack.get_StackXPos() + 10, 14);
			
			m_current->m_next->m_prev = auxNode;
			auxNode->m_prev = m_current;			
			auxNode->m_next = m_current->m_next;
			m_current->m_next = auxNode;
			auxNode = nullptr;

			delete auxNode;
			
			Node* tail = m_current;
			for (int i = PositionofCurrentNode() + 1; i < NumberofNodes(); i++)
			{
				tail = tail->m_next;
				tail->m_stack.set_StackXPos(6 + 10 * i);
				tail->m_stack.DrawStack(0); //0 = black; 3 = cyan; 7 = white;
				tail->m_stack.DrawStack(7); //0 = black; 3 = cyan; 7 = white;
			}
			m_head->m_prev = tail;

			//memcpy(m_current->m_next, auxNode, sizeof(Node));
			//EraseStacks();
			//RedrawStacks();
		}
	}

	void DeleteatPosition()
	{
		if (m_head != nullptr)
		{
			m_current->m_stack.DrawStack(0); //0 = black; 3 = cyan; 7 = white;
			if (NumberofNodes() == 1)
			{
				m_head = nullptr;
				m_current = nullptr;
			}
			else
			{
				Node* auxNode = m_current;

				m_current->m_prev->m_next = m_current->m_next;
				m_current->m_next->m_prev = m_current->m_prev;
				m_current = m_current->m_next;
				/*auxNode->m_next->m_prev = m_current;
				m_current->m_next = auxNode->m_next;
				m_current = auxNode;*/
				auxNode = nullptr;

				delete auxNode;

				/*this part is not working*/
				Node* tail = m_current;
				for (int i = PositionofCurrentNode(); i < NumberofNodes(); i++)
				{
					tail = tail->m_next;
					tail->m_stack.set_StackXPos(6 + 10 * i);
					tail->m_stack.DrawStack(0); //0 = black; 3 = cyan; 7 = white;
					tail->m_stack.DrawStack(7); //0 = black; 3 = cyan; 7 = white;
				}
				m_head->m_prev = tail;

				EraseStacks();
				RedrawStacks();
			}			
		}
	}

	void MovetoNext()
	{
		if (m_current->m_next != nullptr)
		{
			m_current->m_stack.DrawStack(7); //0 = black; 3 = cyan; 7 = white;
			m_current = m_current->m_next;
			m_current->m_stack.DrawStack(3); //0 = black; 3 = cyan; 7 = white;
		}			
	}
	
	void MovetoPrevious()
	{
		if (m_current->m_prev != nullptr)
		{
			m_current->m_stack.DrawStack(7); //0 = black; 3 = cyan; 7 = white;
			m_current = m_current->m_prev;
			m_current->m_stack.DrawStack(3); //0 = black; 3 = cyan; 7 = white;
		}			
	}

	bool isEmpty() const
	{
		if (m_head == nullptr)
			return true;
		else
			return false;
	}

	Node* getCurrentNode() const
	{
		return m_current;
	}

	~CircularLinkedList()
	{
		/*delete m_head;
		delete m_current;*/
	}
};