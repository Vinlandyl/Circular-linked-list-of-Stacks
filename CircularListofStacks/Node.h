#pragma once
#include "ScreenStack.h"

class Node
{
private:
	ScreenStack stack_;
	Node* prevNode_;
	Node* nextNode_;

public:
	Node()
	{
		prevNode_ = nullptr;
		nextNode_ = nullptr;
	}

	Node(int x, int y)
	{
		//ScreenStack stack_(x, y);
		stack_ = ScreenStack(x, y);
		prevNode_ = nullptr;
		nextNode_ = nullptr;
	}

	ScreenStack getStack() const
	{
		return stack_;
	}

	void setStackXPos(int x)
	{
		stack_.set_StackXPos(x);
	}

	void StackPush(int number)
	{
		stack_.Push(number);
	}

	int StackPop()
	{
		return stack_.Pop();
	}

	Node* getPrevNode() const
	{
		return prevNode_;
	}

	Node* getNextNode() const
	{
		return nextNode_;
	}

	void setPrevNode(Node& node)
	{
		prevNode_ = &node;
	}

	void setNextNode(Node& node)
	{
		nextNode_ = &node;
	}
};