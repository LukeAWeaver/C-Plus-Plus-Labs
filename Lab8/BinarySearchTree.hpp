#include "Node.h"
#include <iostream>
using namespace std;

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
	m_root = nullptr;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree<T>& other)
{
	m_root = new Node<T>(*other.m_root);
}

template <typename T>
BinarySearchTree<T>::~BinarySearchTree()
{
	deleteTree(m_root);
}

template <typename T>
bool BinarySearchTree<T>::add(T value)
{
	if(m_root == nullptr)
	{
		m_root = new Node<T>();
		m_root->setValue(value);
	}
	else
	{
   		add(value);
	}
		return true;
}
template <typename T>
void BinarySearchTree<T>::printTree(Order order) const
{
	if(m_root == nullptr)
	{	
		cout << "Tree is empty!\n";
	}  

}
template <typename T>
void BinarySearchTree<T>::deleteTree(Node<T>* subTree)
{
  if(subTree != nullptr)
  {
    deleteTree(subTree->getLeft());
    deleteTree(subTree->getRight());
    delete subTree;
  }
}
template <typename T>
BSTI BinarySearchTree<T>*:: clone()
{

}
template <typename T>
bool BinarySearchTree<T>::search(T value) const
{
	return true;
}
