#include <iostream>
#include <fstream>
#include "BinarySearchTree.h"
#include "Node.h"
#include "BSTI.h"
#include "Test.h"
#include <string>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;


void printMenu()
{
	cout<<"Input a selection\n"
	<<"1) Add more values to original tree\n"
	<<"2) Copy the original tree\n"
	<<"3) Delete the original tree (one time only)\n"
	<<"4) Print original tree\n"
	<<"5) Print copy\n"
	<<"6) Search original tree\n"
	<<"7) Search copy\n"
	<<"8) Exit\n"
	<<"9) run tests\n"
	<<"Your Choice: \n" << endl;
}
void randBST(int n, BinarySearchTree<int>& BST)
{
	default_random_engine generator(time(nullptr)); //random # gen
	uniform_int_distribution<int> distribution(-2000, 2000);
	for(int i = 0; i < n; i++)
	{
		BST.add(distribution(generator)); //randomly populates BST
	}
}


int main(int argc, char* argv[])
{
	int choice,value,print;
	BSTI<int>* BST = new BinarySearchTree<int>();
	BSTI<int>* temp = nullptr;
	BinarySearchTree<int>::Order PRE = BinarySearchTree<int>::PRE_ORDER;
	BinarySearchTree<int>::Order IN = BinarySearchTree<int>::IN_ORDER;
	BinarySearchTree<int>::Order POST = BinarySearchTree<int>::POST_ORDER;
	Node<int>* s = nullptr;
	Test test;
	string option = argv[1];
	int num = stoi(argv[2]);
	if(option=="-test" && argc==2)
	{
		test.runTests();
	}
	if(option=="-nodes" && argc==3)
	{/*
		randBST(num, *BST);
		while(choice!=8)
		{
			printMenu();
			cin >> choice;
			if(choice==1)
			{
				cin >> value;
				BST->add(value);
			}
			if(choice==2)
			{
				temp= new BinarySearchTree<int>(*BST);
			}
			if(choice==3)
			{
				delete BST;	
			}
			if(choice==4)
			{
				cout << "Pick a printing choice\n"
				<< "1) PreOrder\n"
				<< "2) InOrder\n"
				<< "3) PostOrder\n"
				<< "your choice: ";
				cin >> print;
				if(print==1)
				{
					BST->printTree(PRE);
					cout << endl;
				}
				if(print==2)
				{
					BST->printTree(IN);
					cout << endl;
				}
				if(print==3)
				{
					BST->printTree(POST);
					cout << endl;
				}				
			}
			if(choice==5)
			{
				cout << "Pick a printing choice\n"
				<< "1) Pre\n"
				<< "2) In\n"
				<< "3) Post\n"
				<< "your choice: ";
				cin >> print;
				if(print==1)
				{
					temp->printTree(PRE);
					cout << endl;
				}
				if(print==2)
				{
					temp->printTree(IN);
					cout << endl;
				}
				if(print==3)
				{
					temp->printTree(POST);
					cout << endl;
				}				
			}
		}
	*/}
}
