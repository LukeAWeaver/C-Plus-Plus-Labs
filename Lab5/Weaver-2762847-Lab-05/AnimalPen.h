/**
*	@file : AnimalPen.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: Declaring variables for animalpen
*/
#ifndef ANIMALPEN_H
#define ANIMALPEN_H
#include "Stack.h"
#include "FarmAnimal.h"
#include "Node.h"
using namespace std;

class AnimalPen: public Stack <FarmAnimal*>
{
	public:
	/**
	*  @pre none.
	*  @post creates pointers
	*  @return None
	*/
	AnimalPen();
	/**
	*  @pre none.
	*  @post deletes pointers
	*  @return None
	*/
	~AnimalPen();
	/**
	*  @pre a pointer.
	*  @post adds an animal to stack
	*  @return None
	*/
	void addAnimal(FarmAnimal* animal);
	/**
	*  @pre none.
	*  @post releases an animal
	*  @return None
	*/
	void releaseAnimal();
	/**
	*  @pre none.
	*  @post peeks at next animal in stack
	*  @return None
	*/
	FarmAnimal* peakAtNextAnimal();
	/**
	*  @pre none.
	*  @post checks if the pen is empty
	*  @return true or false
	*/
	bool isPenEmpty();
	FarmAnimal* x;
	FarmAnimal* temp10;

}; 
#endif
