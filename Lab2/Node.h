/**
*	@file : Main.cpp
*	@author :  Luke Weaver
*	@date : 2015.20.15
*	@brief: to declare variables for Node
*/
#ifndef Node_H
#define Node_H

#include <iostream>
using namespace std;

class Node //A Node is a simple container.
{
	public:
	/**
	*  @pre none
	*  @post Constructor Sets m_value to zero Sets m_next to nullptr
	*  @return none
	*/ 
	Node();  
	/**
	*  @pre a value
	*  @post  Sets m_value val
	*  @return none
	*/ 
	void setValue(int val);
	/**
	*  @pre none
	*  @post returns m_value
	*  @return an int
	*/ 
	int getValue() const; 
	/**
	*  @pre A pointer
	*  @post sets m_next
	*  @return none
	*/ 
	void setNext(Node* prev);
	/**
	*  @pre none
	*  @post gets the next node in the list
	*  @return m_next
	*/ 
	Node* getNext() const;
	private:
	int m_value; //the value in the node
	Node* m_next; //a pointer to another node
};
#endif

