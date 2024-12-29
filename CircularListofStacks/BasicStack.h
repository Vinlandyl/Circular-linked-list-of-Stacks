#pragma once

class BasicStack
{
protected:
	int m_elements[5];
	int m_position;

public:
	BasicStack()
	{
		m_position = -1;
		/*for ()
			m_elements[i] = 0;*/
	}

	void Push(int number)
	{
		if (!isFull())
		{
			m_position++;
			m_elements[m_position] = number;
		}
	}

	int Pop()
	{
		if (!isEmpty())
		{
			m_position--;
			return m_elements[m_position + 1];
		}
		else
			return -1;
	}

	int Peek() const
	{
		if (!isEmpty())
		{
			return m_elements[m_position];
		}
		else
			return -1;
	}

	bool isFull() const
	{
		if (m_position == 4)
			return true;
		else
			return false;

	}

	bool isEmpty() const
	{
		if (m_position == -1)
			return true;
		else
			return false;
	}
};

