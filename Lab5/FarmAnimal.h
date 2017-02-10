/**
*	@file : FarmAnimal.h
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: to initialize variables for FarmAnimal
*/
#ifndef FARMANIMAL_H
#define FARMANIMAL_H
#include <string>
using namespace std;
class FarmAnimal
{
	public:
	/**
	*  @pre none
	*  @post sets variables
	*  @return None
	*/
	FarmAnimal();
	/**
	*  @pre none
	*  @post returns a name
	*  @return a string
	*/
	string getName() const;
	/**
	*  @pre a string.
	*  @post sets string to name
	*  @return None
	*/
	void setName(string name);
	/**
	*  @pre none.
	*  @post returns a sound
	*  @return a string
	*/
	string getSound() const;
	/**
	*  @pre a string.
	*  @post sets sound
	*  @return None
	*/
	void setSound(string sound);
	
	protected:

	string m_name;
	string m_sound;
};
#endif
