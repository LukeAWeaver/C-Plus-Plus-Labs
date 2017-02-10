/**
*	@file : Stack.hpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: to transfer/remove data between Node<T>s
*/
#include "PreconditionViolationException.h"
#include "Node.h"

#include <iostream>
#include <stdexcept>
#include <exception>
#define nullptr NULL

using namespace std;

template <typename T>
Stack<T>::Stack()
{
	m_front= nullptr;
	temp= nullptr;
	m_size=0;
}

template <typename T>
Stack<T>::~Stack()
{
	while(!isEmpty())
	{
		pop();
	}
	delete temp;
	delete m_front;
}

template <typename T>
void Stack<T>::pop() throw (PreconditionViolationException) 
{
	temp=nullptr;
	if(m_size==0)
	{
		throw PreconditionViolationException("Exception: Pop attempted on empty stack");
	}
	else
	{
		if(m_size!=1)
		{
			temp=m_front;
			m_front=m_front ->getNext(); 
			delete temp; 
			temp = nullptr;
			m_size--;
		}
		else
		{
			delete m_front;
			m_front=nullptr;
			m_size--;
		}
	}
}

template <typename T>
bool Stack<T>:: isEmpty() const
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

template <typename T>
int Stack<T>:: size() const
{
	return m_size;
}

template <typename T>
T Stack<T>:: peek() const throw(PreconditionViolationException)
{
	if(isEmpty())
	{	
		throw PreconditionViolationException("Exception: Peek attempted on empty stack");
	}
	else
	{
	return (m_front ->getValue());
	}
}
template <typename T>
void Stack<T>::print() const
{
	T x=0;
	if(!isEmpty())
	{
		Node<T>* temp=m_front;
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
		cout <<"";
	}
}
template <typename T>
void Stack<T>::push(const T value)
{
	temp= new Node<T>();
	temp -> setValue(value); 
	if(m_size==0)
	{
		m_front=temp; 
	}
	else
	{
		temp->setNext(m_front); 
		m_front=temp; 
	}	
	m_size++;
	temp=nullptr;
}

