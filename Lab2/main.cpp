/**
*	@file : Main.cpp
*	@author :  Luke Weaver
*	@date : 2015.20.15
*	@brief: driver for the program
*/

#include <iostream>
#include "Test.h"
#include "LinkedList.h"
#include "Node.h"

using namespace std;
void printMenu()
{
	cout << "\n\nSelect from the following menu:\n"
	<< "1) Add to the front of the list\n" //add front
	<< "2) Add to the end of the list\n" //add back
	<< "3) Remove from front of the list\n" //remove front cal
	<< "4) Remove from back of the list\n"//call remove back
	<< "5) Print the list\n"
	<< "6) Search for value\n"
	<< "7) Exit\n"
	<< "8) Run tests\n"
	<< "Enter your choice: ";
}
int main()
{
	Test myTester(cout);
	int x=0;
	int value;
	LinkedList list = LinkedList();
	do
	{
		printMenu();
		cin >> x;
		if(x>8 || x<1)
		{
			cout << "That is not an option, choose an option between 1-8." <<endl;
		} 
		else
		{
			cout << "enter your choice: you chose: " << x << endl;
			if(x==1)
			{
				cout << "Input a value to add: ";
				cin >>  value;
				cout << "Adding " << value << " to the list\n" <<endl;
				list.addFront(value);			
			}
			if(x==2)
			{
				cout << "Input a value to add: ";
				cin >>  value;
				cout << "Adding " << value << " to the list\n" <<endl;
				list.addBack(value);
			}
			if(x==3)
			{
				cout << "Attempting removal from front of list.";
				if(list.removeFront()==true)
				{
					cout << " Removal successful.\n" <<endl;
				}
				else
				{
					cout << "There are no values to remove" <<endl;
				}
			}
			if(x==4)
			{
				cout << "Attempting removal from back of list.";
				if(list.removeBack()==true)
				{
				cout << " Removal successful.\n" <<endl;
				}
				else
				{
				cout << "There are no values to remove" << endl;
				}
			}
			if(x==5)
			{
				cout << "Printing list:" <<endl;
				list.printList();
			}
			if(x==6)
			{
				cout <<"Enter a value to search for: ";
				cin >> value;
				cout << "Searching for " << value << "..." <<endl;
				if(list.search(value)==true)
				{
					cout << value << " is in the list." <<endl;
				}
				else
				{
					cout << value << " is not in the list" << endl;
				}		
			}
			if(x==7)
			{
				list.~LinkedList();
			}
			if(x==8)
			{
				myTester.runTests();		
			}
		}	
	}
	while(x!=7);
	cout << "\nExiting..." <<endl;
}
