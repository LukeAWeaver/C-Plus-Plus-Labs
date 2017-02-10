/**
*	@file : NumberFileDriver.cpp
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: Driver for numberfilegenerator
*/

#include "NumberFileDriver.h"
#include "NumberFileGenerator.h"
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

void NumberFileDriver::printHelpMenu()
{
	cout << "\nUse Number File Generator in one of the following ways:\n\n"
			<< "./prog -create -a filename amount\n"
			<< "./prog -create -d filename amount\n"
			<< "./prog -create -s filename amount value\n"
			<< "./prog -create -r filename amount min max\n"
			<< "Option explainations:\n"
			<< "\t-a for ascending\n"
			<< "\t-d for descending\n"
			<< "\t-s for a single value\n"
			<< "\t-r for random values\n"
			<< "\tfilename is the ouput file name\n"
			<< "\tamount is the amount of random numbers to place in the file\n"
			<< "\tvalue is the single number that will be written to file in -s mode\n"
			<< "\tmin is the low end of the range of random numbers\n"
			<< "\tmax is the high end (non-inclusive) of the range of random numbers\n";

}

bool NumberFileDriver::isValidOption(string option)
{
	if(option =="-a" || option =="-d" || option =="-s" || option =="-r")
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void NumberFileDriver::run(int argc, char** argv)
{
	string inputAsString(argv[2]);
	if(isValidOption(argv[2]) == true)
	{
		if(strcmp( argv[2], "-a") == 0)
		{
			NumberFileGenerator::ascending(string(argv[3]), atoi(argv[4]));
			cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
		}
		else if(strcmp( argv[2], "-d") == 0)
		{
			NumberFileGenerator::descending(string(argv[3]), atoi(argv[4]));
			cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
		}
		else if(strcmp( argv[2], "-s") == 0)
		{
			NumberFileGenerator::singleValue(string(argv[3]), atoi(argv[4]), atoi(argv[5]));
			cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
		}
		else if(strcmp( argv[2], "-r") == 0)
		{
			int size = atoi(argv[4]);
			int min = atoi(argv[5]);
			int max = atoi(argv[6]);
			NumberFileGenerator::random(string(argv[3]), size, min, max);
			cout<<argv[4]<<" numbers stored in "<<argv[3]<<"\n";
		}
	}
	else
	{
		printHelpMenu();
	}

}
