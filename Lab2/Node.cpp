/**
*	@file : Node.cpp
*	@author :  Luke Weaver
*	@date : 2015.20.15
*	@brief: to store data in nodes
*/

#include <iostream>
#include "Test.h"
#include "Node.h"
#define nullptr NULL
using namespace std;

Node::Node()
{
	m_value=0;
	m_next=nullptr;
}
//sets value
void Node:: setValue(int val)
{
	m_value=val;
}
//gets value
int Node:: getValue() const
{
	return m_value;
}
//sets next
void Node:: setNext(Node* prev)
{
	m_next=prev;
}
//gets next
Node* Node:: getNext() const
{
	return m_next;
}
