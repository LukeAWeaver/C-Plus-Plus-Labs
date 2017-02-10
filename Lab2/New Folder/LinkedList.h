/**
*	@file : LinkedList.h
*	@author :  Luke Weaver
*	@date : 2015.20.15
*	Purpose: to declare variables in linkedlist
*/
#ifndef LinkedList_H
#define LinkedList_H
#include "Node.h"
#include <iostream>
using namespace std;
class LinkedList //The LinkedList class will be in control of generating a list or sequence of Nodes.
{
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a LinkedList instance
	*  @return None
	*/
	LinkedList();
	/**
	*  @pre LinkedList that exist
	*  @post Deletes all nodes in the list.
	*  @return none
	*/
	~LinkedList(); 
	/**
	*  @pre none
	*  @post returns true if the list is empty, false otherwise.
	*  @return true if empty or false if not empty
	*/	
	bool isEmpty() const; 
	/**
	*  @pre none
	*  @post checks size of list
	*  @return returns the number of elements in the list.
	*/
	int size() const;
	/**
	*  @pre none
	*  @post searches method for values in nodes
	*  @return returns true is the value is in the list, false otherwise.
	*/ 
	bool search(int value) const; 
	/**
	*  @pre a value
	*  @post prints the list to the console. "List empty" if it is empty
	*  @return none
	*/ 	
	void printList() const;
	/**
	*  @pre a value
	*  @post One new element added to the end of the list.
	*  @return none
	*/ 	
	void addBack(int value); 
	/**
	*  @pre a value
	*  @post One new element added to the front of the list.
	*  @return none
	*/ 	
	void addFront(int value);
	/**
	*  @pre none
	*  @post One element is removed from the back of the list.
	*  @return Returns true if the back element was removed, false if the list is empty.
	*/ 	
	bool removeBack(); 
	/**
	*  @pre none
	*  @post One element is removed from the front of the list.
	*  @return Returns true if the front element was removed, false if the list is empty.
	*/ 
	bool removeFront(); 
	
	private:
	Node* m_front;
	int m_size;
	Node* temp;
	Node* last;
};
#endif
