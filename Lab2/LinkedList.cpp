/**
*	@file : LinkedList.cpp
*	@author :  Luke Weaver
*	@date : 2015.20.15
*	@brief: to transfer/remove data between nodes
*/

#include <iostream>

#include "LinkedList.h"
#include "Node.h"
#define nullptr NULL

using namespace std;

LinkedList::LinkedList()
{
	m_front= nullptr;
	temp= nullptr;
	last= nullptr;
	m_size=0;
}

LinkedList::~LinkedList()
{
while(!isEmpty())
	{
	removeFront();
	}
delete temp;
delete m_front;
}

bool LinkedList:: isEmpty() const
{
	if(m_front==nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
} 
//DONE
int LinkedList:: size() const
{
return m_size;
}

bool LinkedList::search(int value) const
{
	Node* temp = m_front;
	while(temp != nullptr)
	{
		if(temp -> getValue()==value)
		{
			return true;
		}
		else
		{
			temp=temp->getNext();
		}
	}
	return false;
}
void LinkedList::printList() const
{
	int x;
	if(!isEmpty())
	{
		Node* temp=m_front;
		while(temp!=nullptr)
		{
			x= temp -> getValue();
			cout << x << " ";
			temp=temp->getNext();
		}
		temp=nullptr;
	}
	else 
	{
		cout <<"" ;
	}
}

//REVISE??
void LinkedList::addBack(int value)
{
	temp=nullptr;
	last=nullptr;
	if(isEmpty())
	{
		m_front= new Node();
		m_front-> setValue(value);
		m_size++;
	}
	else
	{
		last=m_front; //starting at first node
		while(last->getNext()!=nullptr) //goes to end of list
		{
			last=last->getNext();
		}
		temp = new Node();
		temp -> setValue(value);
		last -> setNext(temp);
		m_size++;
	}
}
bool LinkedList::removeBack()
{
	if(isEmpty())
	{
		return false; // nothing to remove
	}
	else
	{
		Node* temp2 = nullptr;
		if(m_size==1)
		{
			delete m_front;
			m_front=nullptr;	
		}
		else
		{
			last=m_front; //starting at first node and pointing to second
			while((last->getNext())!=nullptr)		
			{
				temp2=last;			
				last=last->getNext(); //goes to end of list
			}
			temp2->setNext(nullptr);	
			delete last; //deletes last object
			last=nullptr;//deletes the pointer
			m_size--; //reduces counter			
		}
	}
		return true; 
}
//O1 DONE
void LinkedList::addFront(int value)
{
	temp= new Node(); //creates new node
	temp -> setValue(value); //sets value that node is pointing at
	//temp = new Node();
	if(m_size==0)
	{
		m_front=temp; // if there is only 1 node which is the one we just created just point m_front to temp
	}
	else
	{
		temp->setNext(m_front); //links first node that temp is pointing at to the next node that already existed
		m_front=temp; //directs m_front to the first node in the list	= takes value of node and where its pointing
	}	
	m_size++;
	temp=nullptr; //temp guides m_front to the first node
}
bool LinkedList::removeFront()
{
	temp=nullptr;
	if(isEmpty())
	{
		return (false);
	}
	else
	{
		temp=m_front;
		m_front=m_front ->getNext(); 
		delete temp; 
		temp = nullptr;
		m_size--;
		return true;
	}
}
/*
	LinkedList(); //constructor sets m_front to nullptr and m_size to zero
	~LinkedList(); //deeestructor Deletes all nodes in the list.
	bool isEmpty() const; //returns true if the list is empty, false otherwise.
	int size() const; //returns the number of elements in the list.
	bool search(int value) const; //returns true is the value is in the list, false otherwise.
	void printList() const; //prints the list to the console. "List empty" if it is empty
	void addBack(int value); //One new element added to the end of the list.
	void addFront(int value); //One new element added to the front of the list.
	bool removeBack(); //One element is removed from the back of the list. Returns true if the back element was removed, false if the list is empty.
	bool removeFront(); //One element is removed from the front of the list. returns True if the front element was removed, false if the list is empty.
	*/
