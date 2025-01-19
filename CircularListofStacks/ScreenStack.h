#pragma once
#include <iostream>
#include <windows.h>
#include "BasicStack.h"
#include "MoveCursor.h"
#include "Colours.h"

class ScreenStack : public BasicStack
{
private:
	int x_, y_;
	HANDLE hConsole_;

public:	
	void DrawStack(int color)
	{
		SetConsoleTextAttribute(hConsole_, color); //0 = black; 3 = cyan; 7 = white;
		for (int i = 0; i < 5; i++)
		{
			gotoxy(x_, y_ + i);
			std::cout << (char)186 << "   " << (char)186; //Vertical line
		}
		gotoxy(x_, y_ + 5);
		std::cout << (char)200;  //Bottom left corner

		for (int i = 1; i < 4; i++)
		{
			gotoxy(x_ + i, y_ + 5);
			std::cout << (char)205;  //Bottom line
		}
		std::cout << (char)188; //Bottom right corner

		if (!isEmpty())
			for (int i = 0; i <= position_; i++)
			{
				gotoxy(x_ + 2, y_ + 4 - i);
				std::cout << elements_[i];
			}
		SetConsoleTextAttribute(hConsole_, WHITE);
	}

public:
	ScreenStack()
	{ }
	
	ScreenStack(int x, int y)
	{
		x_ = x;
		y_ = y;
		hConsole_ = GetStdHandle(STD_OUTPUT_HANDLE);

		DrawStack(CYAN);
	}

	void Push(int number) override
	{
		if (!isFull())
		{
			position_++;
			elements_[position_] = number;
			gotoxy(x_ + 2, y_ + 4 - position_);
			SetConsoleTextAttribute(hConsole_, CYAN);
			std::cout << Peek();
			SetConsoleTextAttribute(hConsole_, WHITE);
		}
	}

	int Pop() override
	{
		if (!isEmpty())
		{
			position_--;
			gotoxy(x_ + 2, y_ + 3 - position_);
			SetConsoleTextAttribute(hConsole_, BLACK);
			std::cout << " ";
			SetConsoleTextAttribute(hConsole_, WHITE);
			return elements_[position_ + 1];
		}
		else
			return -1;
	}
	
	int get_StackXPos() const
	{
		return x_;
	}

	void set_StackXPos(int x)
	{
		x_ = x;
	}
};
