/**
*	@file : Chicken.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: Declaring variables for chicken
*/
#ifndef CHICKEN_H
#define CHICKEN_H
#include "FarmAnimal.h"
#include <iostream>
using namespace std;
class Chicken: public FarmAnimal
{
	public:
	/**
	*  @pre none.
	*  @post sets values
	*  @return None
	*/
	Chicken();
	/**
	*  @pre none.
	*  @post deletes pointers
	*  @return None
	*/
	~Chicken();
	protected:
	/**
	*  @pre none.
	*  @post gets eggs
	*  @return an in
	*/
	int getEggs() const;
	/**
	*  @pre an int.
	*  @post sets egg quantity
	*  @return None
	*/
	void setEggs(int eggs);
	int m_eggs;
};
#endif
