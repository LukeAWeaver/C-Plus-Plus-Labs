/**
*	@file : Main.cpp
*	@author :  Luke Weaver
*	@date : 2015.30.15
*	@brief: driver for the program
*/

#include <iostream>
#include "Test.h"
#include "DoubleLinkedList.h"
#include "Node.h"
#include <stdexcept>

using namespace std;

void printMenu()
{
	std::cout << 	"\n\nMake choice\n"
		<<	"1) push value onto front\n"
		<<	"2) push value onto back\n"
		<<	"3) insert behind a value\n"
		<<	"4) insert ahead of a value\n"
		<<	"5) remove front value\n"
		<<	"6) remove back value\n"
		<<	"7) remove specific value\n"
		<<	"8) print list\n"
		<<	"9) Quit\n"
		<< 	"10) Run Tests\n"
		<< 	"Your choice: ";
}

int main()
{
	Test myTester(cout);
	int x=0;
	int value;
	int insert;
	DoubleLinkedList<int> list;

	do
	{
		printMenu();
		cin >> x;
		if(x>10 || x<1)
		{
			cout << "That is not an option, choose an option between 1-10." <<endl;
		} 
		else
		{
			cout << "\nyou chose: " << x << endl;
			if(x==1)
			{
				cout << "Give a value.";
				cin >>  value;
				cout << value << " added to front of list.\n" <<endl;
				list.pushFront(value);			
			}
			if(x==2)
			{
				cout << "Give a value.";
				cin >>  value;
				cout << value << " added to back of list.\n" <<endl;
				list.pushBack(value);
			}
			if(x==3)
			{	
				try
				{
					cout <<"Give a value to insert." <<endl;
					cin >> value;
					cout <<"Pick a value to insert behind.\n" <<endl;
					cin >> insert;
					cout <<"Attempting to insert " << value << " behind " <<insert <<endl;
					list.insertBehind(insert, value);
				}
				catch (runtime_error& e)
				{
					cout << e.what()<< '\n';
				}
			}
			if(x==4)
			{
				try
				{
					cout <<"Give a value to insert." <<endl;
					cin >> value;
					cout <<"Pick a value to insert ahead of." <<endl;
					cin >> insert;
					cout <<"Attempting to insert " << value << " ahead of " <<insert <<endl;
					list.insertAhead(insert, value);
				}
				catch (runtime_error& e)
				{
					cout << e.what()<< '\n';
				}
			}	
			if(x==5)
			{
				if(list.removeFront()==true)
				{
					cout << " Front of list removed.\n" <<endl;
				}
				else
				{
					cout << "List empty" <<endl;
				}
			}
			if(x==6)
			{
				if(list.removeBack()==true)
				{
					cout << " Back of list removed.\n" <<endl;
				}
				else
				{
					cout << "List empty" << endl;
				}
			}

			if(x==7) //search and remove
			{
				cout<< "Give a value to remove." <<endl;
				cin >> value;
				if(list.find(value)!=nullptr)
				{
					list.remove(value);
					cout << value << " removed from list." <<endl;
				}
				else
				{
					cout << value << " could not be removed from list." << endl;
				}		
			}
			if(x==8)
			{
				list.printList();
			}
			if(x==9)
			{
				list.~DoubleLinkedList();
			}
			if(x==10)
			{
				myTester.runTests();		
			}
		}	
	}
	while(x!=9);
	cout << "\n Program ending..." <<endl;
}
