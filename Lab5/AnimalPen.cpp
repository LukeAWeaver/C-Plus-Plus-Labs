/**
*	@file : AnimalPen.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: driver for animalpen
*/
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Node.h"
using namespace std;
AnimalPen ::AnimalPen()
{
}
AnimalPen::~AnimalPen()
{
}
void AnimalPen:: addAnimal(FarmAnimal* animal)
{
	push(animal);
}
void AnimalPen:: releaseAnimal()
{
	pop();	
}
FarmAnimal* AnimalPen:: peakAtNextAnimal()
{
	if(size()==1)
	{
		return peek();
	}
	else
	{
		next= next -> getNext();
		FarmAnimal* x = next -> getValue();
	 return (x);
	}
}
bool AnimalPen:: isPenEmpty()
{
	if(isEmpty())
	{
		return true;
	}
	else
	{
		return false;	
	}
}
