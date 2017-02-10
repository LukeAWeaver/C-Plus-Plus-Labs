/**
*	@file : Cow.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: initialize variables for Cow
*/
#ifndef COW_H
#define COW_H
#include "FarmAnimal.h"
#include "Node.h"
#include <iostream>
#include <string>
using namespace std;
class Cow : public FarmAnimal 
{
	public:
	/**
	*  @pre none.
	*  @post initializes variables
	*  @return a double
	*/
	Cow();
	/**
	*  @pre none.
	*  @post get milk produced
	*  @return a double
	*/
	double getMilkProduced() const;
	/**
	*  @pre a double.
	*  @post sets milk produced
	*  @return None
	*/
	void setMilkProduced(double gallons);


	protected:
	double m_milkProduced;
};
#endif
