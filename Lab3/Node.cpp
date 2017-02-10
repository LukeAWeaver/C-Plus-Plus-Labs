/**
*	@file : Node<T>.cpp
*	@author :  Luke Weaver
*	@date : 2015.23.15
*	@brief: to store data in nodes
*/

#define nullptr NULL
using namespace std;

template <typename T>
Node<T>::Node()
{
	m_value=0;
	m_next=nullptr;
}

//sets value
template <typename T>
void Node<T>:: setValue(T val)
{
	m_value=val;
}

//gets value
template <typename T>
T Node<T>:: getValue() const
{
	return m_value;
}

//sets next
template <typename T>
void Node<T>:: setNext(Node* prev)
{
	m_next=prev;
}

//gets next
template <typename T>
Node<T>* Node<T>:: getNext() const
{
	return m_next;
}
