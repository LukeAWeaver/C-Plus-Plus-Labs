/**
*	@file : Node<T>.cpp
*	@author :  Luke Weaver
*	@date : 2015.30.15
*	@brief: to store data in nodes
*/

#define nullptr NULL
using namespace std;

template <typename T>
Node<T>::Node()
{
	m_value=T();
	m_next=nullptr;
	m_previous=nullptr;
}

//sets value
template <typename T>
void Node<T>:: setValue(T val)
{
	m_value=T (val);
}

//gets value
template <typename T>
T Node<T>:: getValue() const
{
	return m_value;
}

//sets next
template <typename T>
void Node<T>:: setNext(Node<T>* prev)
{
	m_next=prev;
}

template <typename T>
void Node<T>:: setPrevious(Node<T>* prev)
{
	m_previous=prev;
}

template <typename T>
Node<T>* Node<T>:: getPrevious() const
{
	return m_previous;
}

//gets next
template <typename T>
Node<T>* Node<T>:: getNext() const
{
	return m_next;
}
