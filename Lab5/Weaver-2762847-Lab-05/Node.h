/**
*	@file : Node.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: to declare variables for Node
*/
#ifndef NODE_H
#define NODE_H

#include <iostream>
using namespace std;

template <typename T>
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
	void setValue(T val);
	/**
	*  @pre none
	*  @post returns m_value
	*  @return an int
	*/ 
	T getValue() const; 
	/**
	*  @pre A pointer
	*  @post sets m_next
	*  @return none
	*/ 
	void setNext(Node<T>* prev);
	/**
	*  @pre none
	*  @post gets the next node in the list
	*  @return m_next
	*/ 
	Node<T>* getNext() const;
	/**
	*  @pre a node pointer 
	*  @post sets what the node is looking at previously
	*  @return none
	*/ 
	void setPrevious(Node<T>* prev);
	/**
	*  @pre none 
	*  @post  the previous node's value that the pointer is looking at
	*  @return returns previous nodes value
	*/ 
	Node<T>* getPrevious() const;
	private:
	T m_value; //the value in the node
	Node<T>* m_next; //a pointer to another node
	Node<T>* m_previous;
};
#include "Node.hpp"
#endif

