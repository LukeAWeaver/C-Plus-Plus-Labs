/**
*	@file : DoubleLinkedList.cpp
*	@author :  Luke Weaver
*	@date : 2015.23.15
*	@brief: to transfer/remove data between Node<T>s
*/

#include <iostream>

#include "DoubleLinkedList.h"
#include "Node.h"
#define nullptr NULL

using namespace std;

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front= nullptr;
	temp= nullptr;
	last= nullptr;
	m_size=0;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
while(!isEmpty())
	{
	removeFront();
	}
delete temp;
delete m_front;
}

template <typename T>
void DoubleLinkedList<T>::insertAhead(T listValue, T newValue) throw (runtime_error)
{

}

template <typename T>
void DoubleLinkedList<T>:: insertBehind(T listValue, T newValue) throw (runtime_error)
{

}
template <typename T>
bool DoubleLinkedList<T>:: isEmpty() const
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

//DONE
template <typename T>
int DoubleLinkedList<T>:: size() const
{
return m_size;
}

template <typename T>
Node<T>* DoubleLinkedList<T>:: find(T value) const
{
	Node<T>* temp = m_front;
	while(temp != nullptr)
	{
		if(temp -> getValue()==value)
		{
			return (temp);
		}
		else
		{
			temp=temp->getNext();
		}
	}
	return nullptr;
}

template <typename T>
bool DoubleLinkedList<T>::remove(T value){

return true;
}

template <typename T>
void DoubleLinkedList<T>::printList() const
{
	int x;
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
		cout <<"" ;
	}
}


//REVISE??
template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	temp=nullptr;
	last=nullptr;
	if(isEmpty())
	{
		m_front= new Node<T>();
		m_front-> setValue(value);
		m_size++;
	}
	else
	{
		last=m_front; //starting at first Node<T>
		while(last->getNext()!=nullptr) //goes to end of list
		{
			last=last->getNext();
		}
		temp = new Node<T>();
		temp -> setValue(value);
		last -> setNext(temp);
		m_size++;
	}
}

template <typename T>
bool DoubleLinkedList<T>::removeBack()
{
	if(isEmpty())
	{
		return false; // nothing to remove
	}
	else
	{
		Node<T>* temp2 = nullptr;
		if(m_size==1)
		{
			delete m_front;
			m_front=nullptr;	
		}
		else
		{
			last=m_front; //starting at first Node<T> and pointing to second
			while((last->getNext())!=nullptr)		
			{
				temp2=last;			
				last=last->getNext(); //goes to end of list
			}
			temp2->setNext(nullptr);	
			delete last; //deletes last object
			last=nullptr;//deletes the pointer
			m_size--; //reduces counter			
		}
	}
		return true; 
}

//O1 DONE
template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	temp= new Node<T>(); //creates new Node<T>
	temp -> setValue(value); //sets value that Node<T> is pointing at
	//temp = new Node<T>();
	if(m_size==0)
	{
		m_front=temp; // if there is only 1 Node<T> which is the one we just created just point m_front to temp
	}
	else
	{
		temp->setNext(m_front); //links first Node<T> that temp is pointing at to the next Node<T> that already existed
		m_front=temp; //directs m_front to the first Node<T> in the list	= takes value of Node<T> and where its pointing
	}	
	m_size++;
	temp=nullptr; //temp guides m_front to the first Node<T>
}

template <typename T>
bool DoubleLinkedList<T>::removeFront()
{
	temp=nullptr;
	if(isEmpty())
	{
		return (false);
	}
	else
	{
		temp=m_front;
		m_front=m_front ->getNext(); 
		delete temp; 
		temp = nullptr;
		m_size--;
		return true;
	}
}
