/**
*	@file : StackInterface.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: to declare variables in StackInterface
*/
#ifndef STACKINTERFACE_H
#define STACKINTERFACE_H
#include "Node.h"
#include "PreconditionViolationException.h"
#include <iostream>
using namespace std;

template <typename T>
class StackInterface //The StackInterface class will be in control of generating a list or sequence of Nodes.
{
	public:
	/**
	*  @pre Stackinterface exists.
	*  @post deletes pointers
	*  @return None
	*/
	virtual ~StackInterface() {};
	/**
	*  @pre None
	*  @post Checks size of stacks
	*  @return returns true if the stack is empty, false otherwise
	*/
	virtual bool isEmpty() const = 0;
	/**
	*  @pre an int
	*  @post Adds an entry added to top of stack
	*  @return None
	*/
	virtual void push(const T newEntry) = 0;
	/**
	*  @pre assumes the stack is not empty top of the stack is removed  
	*  @post throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
	*  @return None
	*/
	virtual void pop() throw(PreconditionViolationException) = 0;
	/**
	*  @pre assumes the stack is not empty  
	*  @post throws PreconditionViolationException when a pop is attempted on an empty stack. Does not return a value in this case.
	*  @return throws a PreconditionViolationException is attempted on an empty stack. Does not return a value in this case.
	*/
	virtual T peek() const throw(PreconditionViolationException) = 0;
	/**
	*  @pre assumes the stack is not empty  
	*  @post returns the size of the stack
	*  @return value of stack
	*/
	virtual int size() const = 0;
	/**
	*  @pre a list  
	*  @post prints the contents of the stack or prints the empty string if it is empty
	*  @return none
	*/
	virtual void print() const = 0;
};
#endif
