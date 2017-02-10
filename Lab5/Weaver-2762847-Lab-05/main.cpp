/**
*	@file : main.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: driver for program
*/
#include "AnimalPen.h"
#include "FarmAnimal.h"
#include "Cow.h"
#include "Chicken.h"
#include "Node.h"
#include "CyberChicken.h"
#include <iostream>
#include <string>

using namespace std;

void goodbyeMessage(const FarmAnimal& animal)
{
	{
	cout << "Upon release the " << animal.getName() << " said " << animal.getSound() << endl;
	}
}

int main()
{
	string answer = "n";
	int type =0;
	double quantity=0;
	double gallons=0;
	double eggs=0;

	AnimalPen* ap = new AnimalPen();
	FarmAnimal* temp=nullptr;
	do
	{
		do
		{
			cout << "Select an animal to add to the pen: " << endl;
			cout << "1.) Cow (Produces Milk)" <<endl;
			cout << "2.) Chicken (cannot lay eggs)" <<endl;
			cout << "3.) Cyber Chicken (Seems dangerous but lays eggs)" <<endl;
			cout <<"---------------------------------------------------" <<endl;
			cin >> type;
			if(type==1)
			{
				FarmAnimal* cow2 = new Cow();
				Cow* cow = static_cast<Cow*>(cow2);   
				cout <<"choice: How many gallons of milk did this cow produce?: " <<endl;
				cin >> quantity;
				cow -> setMilkProduced(quantity);
				ap -> addAnimal(cow);
			}		
			else if(type==2)
			{
				FarmAnimal* chicken2 = new Chicken();
				Chicken* chicken = static_cast<Chicken*>(chicken2); 
				cout <<"choice: Add an eggless chicken to the pen? OK. You're the boss." <<endl;
				ap ->addAnimal(chicken);
			}
			else if(type==3)
			{
				FarmAnimal* cyberchicken2= new CyberChicken();
				CyberChicken* cyberchicken = static_cast<CyberChicken*>(cyberchicken2); 
				cout <<"choice: How many eggs did this cyber chicken produce?: " <<endl;
				cin >> quantity;
				cyberchicken -> setCyberEggs(quantity);
				ap ->addAnimal(cyberchicken);
			}
			else
			{
				cout <<"That wasn't a choice, try again. " <<endl;
			}
		}
		while(type>3 || type <0);
		cout << "Done adding animals? (y/n): " <<endl; 
		cin >> answer;	
	}
	while(answer.compare("y")!=0);
	if(ap ->isPenEmpty()==false)
	{
		cout <<" Releasing all animals!" <<endl;
		cout <<"-------------------------"<<endl;
	}	
	while(ap -> isPenEmpty() == false)
	{
		temp = ap -> peek();
		if(temp -> getName()=="Cow")
		{
			Cow* temp2 = static_cast<Cow*>(temp);
			cout << "This cow produced " << temp2 -> getMilkProduced() << " gallons of milk." << endl;
			goodbyeMessage(*ap -> peek());
			gallons= gallons + temp2 -> getMilkProduced();
			ap -> releaseAnimal();
			delete temp2;

		}
		else if(temp -> getName()=="Cyber Chicken")
		{
			CyberChicken* temp2 = static_cast<CyberChicken*>(temp);
			cout <<"This cyber chicken laid " << temp2 -> getCyberEggs() << " cyber eggs. Humanity is in trouble." << endl;
			goodbyeMessage(*ap -> peek());
			eggs = eggs + temp2 -> getCyberEggs();
			ap -> releaseAnimal();
			delete temp2;
		}
		else if(temp -> getName() == "Chicken")
		{
			Chicken* temp2 = static_cast<Chicken*>(temp);
			cout <<"Chicken unable to lay eggs. Perhaps cybornetic implants will help?" <<endl;
			goodbyeMessage(*ap -> peek());
			ap -> releaseAnimal();
			delete temp2;
		}
	}
	delete ap;
	cout << "Your farm produced " << gallons << " of milk and " << eggs << " eggs" << endl;
}
