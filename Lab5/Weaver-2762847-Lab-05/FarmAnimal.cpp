/**
*	@file : FarmAnimal.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: driver for FarmAnimal
*/
#include "FarmAnimal.h"
#include <string>
using namespace std;
FarmAnimal::FarmAnimal() 
{
	m_name="unset";
	m_sound="unset";
}
string FarmAnimal::getName() const
{
	return m_name;
}
void FarmAnimal::setName(string name)
{
	m_name=name;
}
void FarmAnimal::setSound(string sound)
{
	m_sound=sound;
}
string FarmAnimal::getSound() const
{
	return m_sound;
}
