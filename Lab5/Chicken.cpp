/**
*	@file : Chicken.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: driver for chicken
*/
#include "Chicken.h"
using namespace std;
Chicken::Chicken()
{
	m_name = "Chicken";
	m_sound = "Cluck";
}
Chicken::~Chicken()
{
	cout << "Chicken destructor called." <<endl;
}
