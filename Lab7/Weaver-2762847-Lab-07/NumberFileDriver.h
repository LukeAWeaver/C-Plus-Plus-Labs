/**
*	@file : NumberFileDriver.h
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: declare variables and methods for numberfiledriver.cpp
*/
#ifndef NUMBERFILEDRIVER_H
#define NUMBERFILEDRIVER_H
#include <iostream>
#include <string.h>
#include <chrono>
class NumberFileDriver
{
	public:
	/**
	*  @pre  arguments is a valid 2-D array and the arguments contained within are valid.
	*  @post  If the arguments are valid, a number file is created following those specifications.
	*  @return none
	*/
	static void run(int argc, char** argv);
	/**
	*  @pre  none
	*  @post provides user with help menu if user inputs incorrect values 
	*  @return none
	*/
	static void printHelpMenu();
	int min;
	int max;
	int size;
	private:
	/**
	*  @pre  none
	*  @post Prints a menus to help the user use the NumberFileGenerator
	*  @return True is the option passed in is valid. Valid options are: "-a", "-d", "-r", and "-s".	This is case sensitive.
	*/
	static bool isValidOption(std::string option);
};
#endif
