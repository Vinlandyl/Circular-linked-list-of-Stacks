#include <conio.h>
#include "CircularLinkedList.h"
#include "ScreenStack.h"

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

void ManageUI()
{
	CircularLinkedList list = CircularLinkedList(6, 15);
	int option;

	WriteMenu();
	do
	{	option = ReadOption();
		gotoxy(2, 12);
		std::cout << "                                                                 " << std::endl;
	    
		if (option > 0 && option < 8 || option == 75 /*left arrow*/ || option == 77 /*right arrow*/)
		{
			switch (option)
			{
			case 1:
				if (list.NumberofNodes() == 0)
					list.InsertatBeginning();
				else if (list.NumberofNodes() < 5)
					list.InsertatPosition();					
				else
				{
					gotoxy(2, 12);
					std::cout << "You have reached the limit of 5 stacks" << std::endl;
				}
				break;
			case 2:				
				if (!list.isEmpty())
				{	
					gotoxy(2, 12);
					std::cout << "                                                       " << std::endl;
					list.getCurrentNode()->m_stack.ScreenPush();
					//node->getStack().Push(1);  //why is this not working?			
					gotoxy(2, 11);
					std::cout << "Press the number of the option you wish to select: " << std::endl;
				}
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 3:
				if (!list.isEmpty())
					list.getCurrentNode()->m_stack.ScreenPop();
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 4:
				if (!list.isEmpty())
					list.getCurrentNode()->m_stack.ScreenPeek();
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 5:
				if (!list.isEmpty())
					list.getCurrentNode()->m_stack.ScreenisFull();
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 6:
				if (!list.isEmpty())
					list.getCurrentNode()->m_stack.ScreenisEmpty();
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 7:
				if (!list.isEmpty())
					list.DeleteatPosition();
				else
				{
					gotoxy(2, 12);
					std::cout << "There are no stacks on the list" << std::endl;
				}
				break;
			case 75:
				if (!list.isEmpty())
					list.MovetoPrevious();
				break;
			case 77:
				if (!list.isEmpty())
					list.MovetoNext();
				break;
			}
			gotoxy(53, 11);
			std::cout << " " << std::endl;	
		}
	} while (option != 8);
}