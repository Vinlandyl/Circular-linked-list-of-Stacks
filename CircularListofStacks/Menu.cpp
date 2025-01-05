#include <conio.h>
#include "CircularLinkedList.h"

static void WriteMenu()
{
	gotoxy(0, 0);
	std::cout << "Circular doubly linked list of Stacks" << std::endl;
	std::cout << std::endl;
	std::cout << "  1. Create new stack (max 5)" << std::endl;
	std::cout << "  2. Push item into the stack" << std::endl;
	std::cout << "  3. Pop item of stack" << std::endl;
	std::cout << "  4. Peek top of the stack" << std::endl;
	std::cout << "  5. Check if stack is full" << std::endl;
	std::cout << "  6. Check if stack is empty" << std::endl;
	std::cout << "  7. Delete selected stack" << std::endl;
	std::cout << "  8. Exit" << std::endl;
	std::cout << std::endl;
	std::cout << "  Press the number of the option you wish to select: " << std::endl;
	gotoxy(0, 23);
	std::cout << "  Move between stacks using the arrow keys. The current stack is highlighted in cyan." << std::endl;
	//std::cout << "0123456789 123456789 123456789 123456789 123456789 123456789" << std::endl;
}

static int ReadOption()
{
	int option;
	
	gotoxy(53, 11);
	option = _getch();
	if (option == 224) //reads again if a function or arrow key is pressed
		option = _getch();
	if (option == 75 /*left arrow*/ || option == 77 /*right arrow*/)
		return option;
	else
	{
		_putch(option);
		return option - 48; //converts char to integer
	}	
}

static void ManageNewNode(CircularLinkedList& list)
{
	if (list.NumberofNodes() == 0)
		list.InsertatBeginning();
	else if (list.NumberofNodes() < 5)
		list.InsertatPosition();
	else
	{
		gotoxy(2, 12);
		std::cout << "You have reached the limit of 5 stacks" << std::endl;
	}
}

static void ManageStackPush(CircularLinkedList& list)
{
	int number;

	gotoxy(2, 12);
	std::cout << "                                                       " << std::endl;
	if (!list.getCurrentNode()->getStack().isFull())
	{
		gotoxy(2, 11);
		std::cout << "Press the number you wish to push into the stack    ";
		gotoxy(50, 11);
		do
		{
			number = _getch() - 48; //converts char to interger
		} while (number < 0 || number > 9);
		list.getCurrentNode()->StackPush(number);
	}
	else
	{
		gotoxy(2, 12);
		std::cout << "Can not add new elements. This stack is already full.";
	}	
	gotoxy(2, 11);
	std::cout << "Press the number of the option you wish to select: " << std::endl;
}

static void ManageStackPop(CircularLinkedList& list)
{
	if (!list.getCurrentNode()->getStack().isEmpty())
	{
		int number = list.getCurrentNode()->StackPop();
		gotoxy(2, 12);
		std::cout << "The poped number is: " << number << std::endl;
	}
	else
	{
		gotoxy(2, 12);
		std::cout << "Can not pop elements from the stack. This stack is already empty.";
	}		
}

static void ManageStackPeek(CircularLinkedList& list)
{
	gotoxy(2, 12);
	if (!list.getCurrentNode()->getStack().isEmpty())
		std::cout << "The number at the top of the stack is: " << list.getCurrentNode()->getStack().Peek() << std::endl;
	else
		std::cout << "This stack is empty.";
}

static void ManageStackisFull(CircularLinkedList& list)
{
	gotoxy(2, 12);
	if (list.getCurrentNode()->getStack().isFull())
		std::cout << "This stack is full.";
	else
		std::cout << "This stack is not full.";
}

static void ManageStackisEmpty(CircularLinkedList& list)
{
	gotoxy(2, 12);
	if (list.getCurrentNode()->getStack().isEmpty())
		std::cout << "This stack is empty.";
	else
		std::cout << "This stack is not empty.";
}

static void ManageUserSelection(CircularLinkedList& list, int option)
{
	if (option == 1)
		ManageNewNode(list);
	else if (option > 1 && option < 8 || option == 75 /*left arrow*/ || option == 77 /*right arrow*/)
	{
		if (!list.isEmpty())
		{
			switch (option)
			{
			case 2:
				ManageStackPush(list);
				break;
			case 3:				
				ManageStackPop(list);
				break;
			case 4:
				ManageStackPeek(list);
				break;
			case 5:
				ManageStackisFull(list);
				break;
			case 6:
				ManageStackisEmpty(list);
				break;
			case 7:
				list.DeleteatPosition();
				break;
			case 75:
				list.MovetoPrevious();
				break;
			case 77:
				list.MovetoNext();
				break;
			}
		}
		else
		{
			gotoxy(2, 12);
			std::cout << "There are no stacks on the list" << std::endl;
		}
	}	
}

void ManageUI()
{
	CircularLinkedList list = CircularLinkedList(6, 15);
	int option;

	WriteMenu();
	do
	{	option = ReadOption();
		gotoxy(2, 12);
		std::cout << "                                                                 " << std::endl;
	    ManageUserSelection(list, option);
		gotoxy(53, 11);
		std::cout << " " << std::endl;		
	} while (option != 8);	
}