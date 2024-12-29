#pragma once
#include <iostream>
#include <windows.h>
#include "BasicStack.h"
#include "MoveCursor.h"

class ScreenStack : public BasicStack
{
	int m_x, m_y;
	HANDLE m_hConsole;

public:
	void DrawStack(int color)
	{
		SetConsoleTextAttribute(m_hConsole, color); //0 = black; 3 = cyan; 7 = white;
		for (int i = 0; i < 5; i++)
		{
			gotoxy(m_x, m_y + i);
			std::cout << (char)186 << "   " << (char)186; //Vertical line
		}
		gotoxy(m_x, m_y + 5);
		std::cout << (char)200;  //Bottom left corner

		for (int i = 1; i < 4; i++)
		{
			gotoxy(m_x + i, m_y + 5);
			std::cout << (char)205;  //Bottom line
		}
		std::cout << (char)188; //Bottom right corner

		if (!isEmpty())
			for (int i = 0; i <= m_position; i++)
			{
				gotoxy(m_x + 2, m_y + 4 - i);
				std::cout << m_elements[i];
			}
		SetConsoleTextAttribute(m_hConsole, 7); //0 = black; 3 = cyan; 7 = white;
	}

public:
	ScreenStack()
	{ }
	
	ScreenStack(int x, int y)
	{
		m_x = x;
		m_y = y;
		m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

		DrawStack(3); //3 = cyan
	}

	void ScreenPush()
	{
		int number;

		if (!isFull())
		{
			gotoxy(2, 11);
			std::cout << "Press the number you wish to push into the stack";
			do
			{
				number = _getch() - 48; //converts char to interger
			} while (number < 0 || number > 9);
			
			Push(number);
			gotoxy(m_x + 2, m_y + 4 - m_position);
			SetConsoleTextAttribute(m_hConsole, 3); //3 = cyan
			std::cout << Peek();
			SetConsoleTextAttribute(m_hConsole, 7); //7 = white
		}
		else
		{
			gotoxy(2, 12);
			std::cout << "Can not add new elements. This stack is already full.";
		}
	}

	void ScreenPop()
	{
		gotoxy(2, 12);
		if (!isEmpty())
		{
			std::cout << "The poped number is: " << Pop() << std::endl;
			
			gotoxy(m_x + 2, m_y + 3 - m_position);
			SetConsoleTextAttribute(m_hConsole, 0); //0 = black
			std::cout << " ";
			SetConsoleTextAttribute(m_hConsole, 7); //7 = white
		}
		else
			std::cout << "Can not pop elements from the stack. This stack is already empty.";
	}

	void ScreenPeek()
	{
		gotoxy(2, 12);
		if (!isEmpty())
			std::cout << "The number at the top of the stack is: " << Peek() << std::endl;			
		else
			std::cout << "This stack is empty.";
	}

	void ScreenisFull()
	{
		gotoxy(2, 12);
		if (isFull())
			std::cout << "This stack is full.";
		else
			std::cout << "This stack is not full.";
	}

	void ScreenisEmpty()
	{
		gotoxy(2, 12);
		if (isEmpty())
			std::cout << "This stack is empty.";
		else
			std::cout << "This stack is not empty.";
	}

	int get_StackXPos() const
	{
		return m_x;
	}

	void set_StackXPos(int x)
	{
		m_x = x;
	}
};
