/**
*	@file : Cow.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: initializing variables for cow
*/
#include "Cow.h"
#include <string>
using namespace std;
Cow::Cow()
{
	m_name="Cow";
	m_sound="Moo";
	m_milkProduced=0;
}
double Cow:: getMilkProduced() const
{
	return m_milkProduced;	
}
void Cow:: setMilkProduced(double gallons)
{
	if(gallons<=0)
	{
		m_milkProduced=0;
	}
	else
	{
		m_milkProduced=gallons;
	}
}

