/**
*	@file : CyberChicken.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: initialize CyberChicken Variables
*/
#ifndef CYBERCHICKEN_H
#define CYBERCHICKEN_H
#include "Chicken.h"
#include <iostream>
using namespace std;

class CyberChicken: public Chicken
{
	public:
	/**
	*  @pre none.
	*  @post sets values
	*  @return None
	*/
	CyberChicken();
	/**
	*  @pre none.
	*  @post deletes pointers
	*  @return None
	*/
	~CyberChicken();
	/**
	*  @pre none.
	*  @post returns eggs
	*  @return an int
	*/
	int getCyberEggs() const;
	/**
	*  @pre an int
	*  @post sets quanity of eggs
	*  @return None
	*/
	void setCyberEggs(int eggs);
};
#endif
