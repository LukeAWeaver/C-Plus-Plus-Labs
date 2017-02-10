/**
*	@file : Main.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.06
*	@brief: driver for the program
*/

#include "Test.h"
#include "Stack.h"
#include "StackInterface.h"
#include "Node.h"
#include "PreconditionViolationException.h"

#include <stdexcept>
#include <iostream>

using namespace std;

void printMenu()
{
	std::cout 	<< "\n\nSelect an action:\n"
			<< "1) Add to stack 1\n"
			<< "2) See what is at the top of stack\n"
			<< "3) Print all stack\n"
			<< "4) Pop stack\n"
			<< "5) Quit\n"
 			<< "6) Run Tests\n"
			<< "Enter choice: ";
}
int main()
{
	int x=0;
	int value=0;
	StackInterface<int>* lane1 = new Stack<int>();
	do
	{
		printMenu();
		cin >> x;
		if(x>6 || x<1)
		{
			cout << "That is not an option, choose an option between 1-10." <<endl;
		} 
		else
		{
			cout << "\nyou chose: " << x << endl;
			if(x==1)
			{
				cout << "What is going in stack 1?: ";
				cin >>  value;
				lane1->push(value);
				cout << lane1 ->peek() << " successfully added to stack 1" 					<<endl;			
			}
			if(x==2)
			{
				try
				{
					cout<< lane1->peek() << " is at the top of stack 1" <<endl;
				}
				catch(std::exception& e)
				{
					cout << e.what();
				}	
			}
			if(x==3)
			{	
				lane1->print();
			}
			if(x==4)
			{
				try
				{
					{
						cout << lane1->peek() << " removed from stack 1" <<endl;
						lane1 -> pop();
					}
				}
				catch(std::exception& e)
				{
					cout << e.what();
				};			
			}	
			if(x==5)
			{
			}
			if(x==6)
			{
				Test myTester(cout);
				myTester.runTests();	
			}
		}	
	}
	while(x!=5);
	delete lane1;
	cout << "\n Program ending" <<endl;
}
