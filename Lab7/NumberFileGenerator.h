/**
*	@file : NumberFileGenerator.h
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to declare methods for numberfilegenerator
*/
#ifndef NUMBERFILEGENERATOR_H
#define NUMBERFILEGENERATOR_H
#include <string>
#include <fstream>
#include <random>
#include <ctime>
class NumberFileGenerator
{
	public:
	/**
	*  @pre  fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the amount of number is ascending order. 
	*  @return none
	*/
	static void ascending(std::string fileName, int amount);
	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the amount of number is descending order.
	*  @return none
	*/
	static void descending(std::string fileName, int amount);
	/**
	*  @pre  fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with the specifed amount of numbers. 
	*  @return none
	*/
	static void random(std::string fileName, int amount, int min, int max);
	/**
	*  @pre fileName is valid path/filename. Amount is greater than zero
	*  @post A file is created with a single number, specified by value, amount of time. 
	*  @return none
	*/
	static void singleValue(std::string fileName, int amount, int value);
};
#endif
