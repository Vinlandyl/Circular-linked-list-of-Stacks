#pragma once
#include "Node.h"

class CircularLinkedList
{
private:
	Node* head_;
	Node* current_;

private:
	int PositionofCurrentNode()
	{
		if (head_ != nullptr)
		{
			Node* auxNode = head_;
			int position = 0;

			while (auxNode != current_)
			{
				auxNode = auxNode->getNextNode();
				position++;
			}
			return position;
		}
		else
			return -1;
	}	

public:

	CircularLinkedList()
	{
		head_ = nullptr;
		current_ = nullptr;
	}

	CircularLinkedList(int x, int y)
	{
		head_ = new Node(x, y);		
		head_->setPrevNode(*head_);
		head_->setNextNode(*head_);
		current_ = new Node(x, y);
		current_ = head_;
	}

	int NumberofNodes()
	{
		if (head_ == nullptr)
			return 0;
		else
		{
			Node* auxNode = head_;
			int counter = 1;

			while (head_ != auxNode->getNextNode() && counter < 5)
			{
				auxNode = auxNode->getNextNode();
				counter++;
			}
			return counter;
		}			
	}

	void InsertatBeginning()
	{
		if (head_ == nullptr)
		{
			head_ = new Node(6, 15);
			head_->setPrevNode(*head_);
			head_->setNextNode(*head_);
			current_ = new Node(6, 15);
			current_ = head_;
		}
	}

	void InsertatPosition()
	{
		if (NumberofNodes() < 6)
		{
			Node* auxNode = new Node(current_->getStack().get_StackXPos() + 10, 15);
			
			current_->getNextNode()->setPrevNode(*auxNode);
			auxNode->setPrevNode(*current_);			
			auxNode->setNextNode(*current_->getNextNode());
			current_->setNextNode(*auxNode);
			auxNode = nullptr;

			delete auxNode;
			
			Node* tail = current_;
			for (int i = PositionofCurrentNode() + 1; i < NumberofNodes(); i++)
			{
				tail = tail->getNextNode();				
				tail->setStackXPos(6 + 10 * i);				
				tail->getStack().DrawStack(WHITE);
			}
			head_->setPrevNode(*tail);
			
			//memcpy(current_->getNextNode(), auxNode, sizeof(Node));
		}
	}

	void DeleteatPosition()
	{
		if (head_ != nullptr)
		{
			current_->getStack().DrawStack(BLACK);
			if (NumberofNodes() == 1)
			{
				head_ = nullptr;
				current_ = nullptr;
			}
			else
			{
				Node* auxNode = current_;

				if (current_ == head_)
					head_ = head_->getNextNode();
				
				current_->getPrevNode()->setNextNode(*current_->getNextNode());
				current_->getNextNode()->setPrevNode(*current_->getPrevNode());
				current_ = current_->getNextNode();
				auxNode = nullptr;

				Node* tail = current_;
				for (int i = PositionofCurrentNode(); i < NumberofNodes(); i++)
				{
					tail->getStack().DrawStack(BLACK);
					//tail->stack_.set_StackXPos(6 + 10 * i);
					tail->setStackXPos(6 + 10 * i);
					tail->getStack().DrawStack(WHITE);
					if (tail->getNextNode()!= head_)
						tail = tail->getNextNode();
				}
				head_->setPrevNode(*tail);
				
				current_->getStack().DrawStack(CYAN);
			}			
		}
	}

	void MovetoNext()
	{
		if (current_->getNextNode() != nullptr)
		{
			current_->getStack().DrawStack(WHITE);
			current_ = current_->getNextNode();
			current_->getStack().DrawStack(CYAN);
		}			
	}
	
	void MovetoPrevious()
	{
		if (current_->getPrevNode() != nullptr)
		{
			current_->getStack().DrawStack(WHITE);
			current_ = current_->getPrevNode();
			current_->getStack().DrawStack(CYAN);
		}			
	}

	bool isEmpty() const
	{
		if (head_ == nullptr)
			return true;
		else
			return false;
	}

	Node* getCurrentNode() const
	{
		return current_;
	}

	~CircularLinkedList()
	{
		head_ = nullptr;
		delete head_;
		current_ = nullptr;
		delete current_;
	}
};