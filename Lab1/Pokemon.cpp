/**
*	@file : Pokemon.cpp
*	@author :  Luke Weaver
*	@date : 2015.09.01
*	Purpose: Implementation of Pokemon Class
*/

#include "Pokemon.h"
#include <string>
#include <iostream>
using namespace std;

//initializing variables from Pokemon.h
Pokemon::Pokemon()
{
	m_hp=0;
	m_attackLevel=0;
	m_defenseLevel=0;
	m_name="";
}

//sets
void Pokemon::setname(string name)
{
	 m_name=name;
}
void Pokemon::sethp(int hp)
{
	m_hp=hp;
}
void Pokemon::setatk(int atk){
m_attackLevel=atk;
}
void Pokemon::setdef(int def){
m_defenseLevel=def;
}
//gets
string Pokemon::getname() const{
return m_name;
}
int Pokemon::gethp() const{
return m_hp;
}
int Pokemon::getatk() const{
return m_attackLevel;
}
int Pokemon::getdef() const{
return m_defenseLevel;
}

//reducing current hp
void Pokemon::reducehp(int amount){
m_hp=m_hp-amount;
if(m_hp <0){
m_hp=0;
}
}
