#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "Node.h"
#include "BSTI.h"
using namespace std;

template <typename T>
class BinarySearchTree : public BSTI<T>
{
	public:

  /**
   * enumerated type for printing order
   */
	enum Order 
	{
		PRE_ORDER,
		IN_ORDER,
		POST_ORDER
	};    
  /**
   * @pre none
   * @post sets m_root to nullptr
   * @return none
   */
	BinarySearchTree();
  /**
   * @pre valid BinarySearchTree object was created
   * @post makes a deep copy of the original BinarySearchTree
   * @return none
   */
	BinarySearchTree(const BinarySearchTree<T>& other);
  /**
   * @pre valid BinarySearchTree object was created
   * @post deletes BinarySearchTree object
   * @return none
   */
	~BinarySearchTree();
  
  /**
   * @pre a BST
   * @post Creates a deep copy of this
   * @return a pointer
   */
	BSTI<T>* clone();
  
  /**
   * @pre valid BinarySearchTree object was created
   * @post prints the BinarySearchTree
   * @return none
   */
	bool isEmpty() const;
  /**
   * @pre none
   * @post adds value to BinarySearchTree object
   * @return none
   */
	bool add(T value);
  /**
   * @pre valid BinarySearchTree object was created
   * @post none
   * @return returns the result from search(T value, Node<T>* subtree)
   */
	bool search(T value) const;
	void printTree(Order order) const;
	std::vector<T> treeToVector(Order order) const;

private:
  /**
   * @pre valid BinarySearchTree created
   * @post deletes left subtree, then right, and then node of subtree passed in
   * @return none
   */
  void deleteTree(Node<T>* subTree);  
  
  /**
   * @pre valid BinarySearchTree created
   * @post prints BinarySearchTree
   * @return none
   */
 
  Node<T>* m_root;
};
#include "BinarySearchTree.hpp"
#endif
