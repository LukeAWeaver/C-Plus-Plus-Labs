/**
*	@file : DoubleLinkedList.h
*	@author :  Luke Weaver
*	@date : 2015.30.15
*	@brief: to declare variables in DoubleLinkedList
*/
#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H
#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
class DoubleLinkedList //The DoubleLinkedList class will be in control of generating a list or sequence of Nodes.
{
	public:
	/**
	*  @pre None
	*  @post Creates and initializes a DoubleLinkedList instance
	*  @return None
	*/
	DoubleLinkedList();
	/**
	*  @pre DoubleLinkedList that exist
	*  @post Deletes all nodes in the list.
	*  @return none
	*/
	~DoubleLinkedList(); 
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
	Node<T>* find(T value) const;
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
	void pushBack(T value); 
	/**
	*  @pre a value
	*  @post One new element added to the front of the list.
	*  @return none
	*/ 	
	void pushFront(T value);
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
	/**
	*  @pre a value to remove
	*  @post removes said value.
	*  @return true if value is in list, false if else.
	*/ 
	bool remove(T value);
	/**
	*  @pre a value, a new value 
	*  @post inserts a node and value ahead of specified node
	*  @return none
	*/ 
	void insertAhead(T listValue, T newValue) throw (runtime_error);
	/**
	*  @pre a value, a new value 
	*  @post inserts a node and value behind of specified node
	*  @return none
	*/ 	
	void insertBehind(T listValue, T newValue) throw (runtime_error);
	private:
	Node<T>* m_front;
	Node<T>* m_back;
	int m_size;
	Node<T>* temp;
	Node<T>* prev;
	Node<T>* next;
	Node<T>* temp3;
};
#include "DoubleLinkedList.hpp"
#endif
