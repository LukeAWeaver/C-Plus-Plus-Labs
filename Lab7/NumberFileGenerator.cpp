/**
*	@file : NumberFileGenerator.cpp
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to generate files. reading/writing
*/
#include "NumberFileGenerator.h"
#include "NumberFileDriver.h"

using namespace std;

void NumberFileGenerator::singleValue(string fileName, int amount, int value)
	{
	ofstream file(fileName);
	file<<amount<<endl;
	for(int i = 0; i<amount-1; i++)
	{
		file<<value<<endl;
	}
	file.close();
}

void NumberFileGenerator::ascending(string fileName, int amount)
{
	ofstream file(fileName);
	file<<amount<<endl;
	for(int i = 0; i<amount-1; i++)
	{
		file<<i<<endl; //write to file
	}
	file.close();
}
void NumberFileGenerator::descending(string fileName, int amount)
	{
	ofstream file(fileName);
	file<<amount<<endl;
	for(int i = amount-1; i>0; i--)
	{
		file<<i<<endl; //write to file
	}
	file.close();
}

void NumberFileGenerator::random(string fileName, int amount, int min, int max)
{
   	default_random_engine generator(time(nullptr)); //generator
    	uniform_int_distribution<int> distribution(min, max-1); //sets bounds
	ofstream file(fileName);
	file<<amount << endl;
	int size = amount;
	for(int i = 0; i < size-1; i++)
	{
		file << distribution(generator) << endl;
	}
	file.close();
}
