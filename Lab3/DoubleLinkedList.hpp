/**
*	@file : DoubleLinkedList.cpp
*	@author :  Luke Weaver
*	@date : 2015.23.15
*	@brief: to transfer/remove data between Node<T>s
*/

#include <iostream>
#include <exception>
#define nullptr NULL

using namespace std;

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList()
{
	m_front= nullptr;
	temp= nullptr;
	prev = nullptr;
	m_back= nullptr;
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
void DoubleLinkedList<T>::insertAhead(T listValue,T newValue ) throw (runtime_error) 
{
			Node<T>* temp2 = find(listValue); //<2>
	if(temp2!=nullptr)
		{
			if(temp2 -> getPrevious()!=nullptr) //if not first in list
			{
				Node<T>* temp3 = temp2 -> getPrevious();//<*>2_
				temp = new Node<T>();//*2_  v
				temp ->setNext(temp2); //*2_   v2
				temp3 -> setNext(temp); //_2_* v2 *v
				temp -> setValue(newValue); //_2**
				temp -> setPrevious(temp3);
				temp2 -> setPrevious(temp);
			}		
			else
			{
				temp = new Node<T>();
				m_front=temp;
				m_front -> setValue(newValue);
				m_front -> setNext(temp2);
				temp2 -> setPrevious(m_front);
			}
		m_size++;
		}
	else
	{
		throw runtime_error("The value given isn't in the list. Insert failed.\n");
	}
		
}

template <typename T>
void DoubleLinkedList<T>:: insertBehind(T listValue,T newValue) throw (runtime_error) 
{
	Node<T>* before = find(listValue); //<2>
	if(before!=nullptr)
	{

		if(before ->getNext()!=nullptr) //if its not the last in the list
		{
	
			Node<T>* after = before -> getNext();//<*>
			temp = new Node<T>();//<2><*>  -_-
			temp -> setValue(newValue); //<2><*>   -V-
			before -> setNext(temp); //<2>V<*>
			temp -> setNext(after); //<2>v><*>
			temp -> setPrevious(before);//<2><v><*>
			after -> setPrevious(temp); //<2>*   -V<*>
		}
		else
		{
			temp = new Node<T>();//_
			m_back=temp;
			m_back -> setValue(newValue); //V
			before -> setNext(m_back);//<2>*
			m_back -> setPrevious(before);//<2><*	
		}

	m_size++;
	}
	else
	{
	throw runtime_error("The value given isn't in the list. Insert failed.\n");
	}
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
bool DoubleLinkedList<T>::remove(T value)
{
	if(isEmpty())
	{
		return(false);
	}
	else
	{
		int x =0;	
		temp = m_front;
		next = nullptr;
		temp3 = nullptr;
		while(temp != nullptr)
		{		
			if( temp -> getValue() == value)
			{
				x++;
				if(x == 1) //if first and not only
				{
					next = temp -> getNext();					
					delete temp;	
					m_front= next;
					m_size--;		
					temp = nullptr;
					next = nullptr;
					return(true);
				}				
				else if( m_size == 1) //if first and only
				{				
					delete temp;
					m_front=nullptr;
					m_back= nullptr;
					m_size--;
 				}
				else if (x == m_size) //fix
				{												
					temp3=m_back;
					m_back= temp3 ->getPrevious();
					delete temp3;
					m_back->setNext(nullptr);
					m_size--;
					temp3 = nullptr;
					return(true);
				}
				else
				{
					next = temp -> getNext();
					temp3 = temp -> getPrevious();
					delete temp;
					next -> setPrevious(temp3);	
					temp3 -> setNext(next);					
					m_size--;		
					temp = nullptr;
					next = nullptr;
					temp3 = nullptr;
					return(true);
				}
				
			}
			else
			{
				x++;
				temp = temp->getNext();
			}
		}
	return(false);
	}
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

template <typename T>
void DoubleLinkedList<T>::pushBack(T value)
{
	temp=nullptr;
	m_back=nullptr;
	if(isEmpty())
	{
		m_front= new Node<T>();
		m_front-> setValue(value);
		m_size++;
	}
	else
	{
		m_back=m_front; //starting at first Node<T>
		while(m_back->getNext()!=nullptr) //goes to end of list
		{
			m_back=m_back->getNext();
		}
		temp = new Node<T>();
		temp -> setValue(value);
		m_back -> setNext(temp);
		temp -> setPrevious(m_back);
		m_back = temp;
		temp=nullptr;
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
			temp2=m_back->getPrevious();
			temp2->setNext(nullptr);	
			delete m_back; //deletes last object
			m_back=temp2;//deletes the pointer
			temp2 =nullptr;
			m_size--; //reduces counter			
		}
	}
		return true; 
}

template <typename T>
void DoubleLinkedList<T>::pushFront(T value)
{
	temp= new Node<T>(); //creates new Node<T>
	temp -> setValue(value); //sets value that Node<T> is pointing at
	//temp = new Node<T>();
	if(m_size==0)
	{
		m_front=temp; // if there is only 1 Node<T> which is the one we just created just point m_front to temp
		m_back=temp;	
	}
	else
	{
		temp->setNext(m_front); //links first Node<T> that temp is pointing at to the next Node<T> that already existed
		m_front -> setPrevious(temp);		
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
		if(m_size!=1)
		{
			temp=m_front;
			m_front=m_front ->getNext(); 
			delete temp; 
			temp = nullptr;
			m_size--;
			return true;
		}
		else
		{
			delete m_front;
			m_front=nullptr;
			m_size--;
			return true;
		}
	}
}
