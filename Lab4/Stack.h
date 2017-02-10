/**
*	@file : Stack.h
*	@author :  Luke Weaver
*	@date : 2015.10.06
*	@brief: to declare variables in Stack
*/
#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include <iostream>
#include "StackInterface.h"
#include "PreconditionViolationException.h"
using namespace std;
template <typename T>
class Stack: public StackInterface<T>//The Stack class will be in control of generating a list or sequence of Nodes.
{
	public:
	/**
	*  @pre None.
	*  @post constructor is created
	*  @return None
	*/
	Stack();
	/**
	*  @pre Stackinterface exists.
	*  @post deletes pointers
	*  @return None
	*/
	~Stack();
	/**
	*  @pre None
	*  @post Checks size of stacks
	*  @return returns true if the stack is empty, false otherwise
	*/
	 bool isEmpty() const;
	/**
	*  @pre an int
	*  @post Adds an entry added to top of stack
	*  @return None
	*/
	 void push(const T newEntry);
	/**
	*  @pre assumes the stack is not empty top of the stack is removed  
	*  @post throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
	*  @return None
	*/
	 void pop() throw(PreconditionViolationException);//try catch outside method 
	/**
	*  @pre assumes the stack is not empty  
	*  @post throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
	*  @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
	*/
	 T peek() const throw(PreconditionViolationException);
	/**
	*  @pre assumes the stack is not empty  
	*  @post returns the size of the stack
	*  @return value of stack
	*/
	 int size() const;
	/**
	*  @pre a list  
	*  @post prints the contents of the stack or prints the empty string if it is empty
	*  @return none
	*/
	void print() const;
	private:
	Node<T>* m_front;
	int m_size;
	Node<T>* temp;

};
#include "Stack.hpp"
#endif
