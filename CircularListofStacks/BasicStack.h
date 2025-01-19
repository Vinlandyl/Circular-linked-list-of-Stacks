#pragma once

class BasicStack
{
protected:
	int elements_[5];
	int position_;

public:
	BasicStack()
	{
		position_ = -1;		
	}

	virtual void Push(int number)
	{
		if (!isFull())
		{
			position_++;
			elements_[position_] = number;
		}
	}

	virtual int Pop()
	{
		if (!isEmpty())
		{
			position_--;
			return elements_[position_ + 1];
		}
		else
			return -1;
	}

	int Peek() const
	{
		if (!isEmpty())
		{
			return elements_[position_];
		}
		else
			return -1;
	}

	bool isFull() const
	{
		if (position_ == 4)
			return true;
		else
			return false;

	}

	bool isEmpty() const
	{
		if (position_ == -1)
			return true;
		else
			return false;
	}
};

