/**
*	@file : Pokemon.h
*	@author :  Luke Weaver
*	@date : 2015.09.01
*	Purpose: used to define Pokemon stats
*/
#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std;
class Pokemon
{
	//declaring private variables
	private:
		int m_hp;// the health points of the pokemon
		int m_attackLevel;// the attack level of the pokemon
		int m_defenseLevel;// the defense level of the pokemon
		string m_name;// name of the pokemon
	//declaring public variables		
	public:
		void reducehp(int amount); //reduces hp
		Pokemon(); //constructor
		//gets
		string getname() const;
		int gethp() const;
		int getatk() const;
		int getdef() const;
	
	
		//sets
		void setname(string name);
		void sethp(int hp);
		void setatk(int atk);
		void setdef(int def);
};
#endif
