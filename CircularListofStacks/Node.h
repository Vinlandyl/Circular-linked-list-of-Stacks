#pragma once
#include "ScreenStack.h"

class Node
{
private:
	ScreenStack stack_; //change to object of type T. Then instantiate a Node<ScreenStack>
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

	ScreenStack& getStack() //change to getHoldObject should return a reference to type T object
	{
		return stack_;
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