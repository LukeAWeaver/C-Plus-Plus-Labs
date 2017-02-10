/**
*	@file : Main.cpp
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to run tests and pass arguments to other files
*/
#include "NumberFileDriver.h"
#include "Test.h"
#include "SortDriver.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	Test test(std::cout);
	string mode = argv[1];
	//Check for number file creation flag
	if(mode == "-create")
	{
		NumberFileDriver::run(argc, argv);		
	}
	//Check for sort flag
	else if (mode == "-sort")
	{
		SortDriver::run(argc, argv);
	}
	//Check for test flag
	else if (mode == "-test")
	{
		test.runTests();
	}
	else
	{	
		std::cout<<"Invalid parameters. Check the order of your options\n";
		NumberFileDriver::printHelpMenu();
		SortDriver::printHelpMenu();
	}
}
