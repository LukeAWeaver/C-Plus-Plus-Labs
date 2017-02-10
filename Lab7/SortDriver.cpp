/**
*	@file : SortDriver.cpp
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: to sort files 
*/
#include "SortDriver.h"
#include <string.h>
#include <iostream>
#include "Sorts.h"
#include "NumberFileGenerator.h"
#include <random>
#include <ctime>
#include <chrono>
#include <cassert>
#include <functional>
#include <fstream>
using namespace std;

void SortDriver::printHelpMenu()
{
	std::cout << "\nSorting is done one of the following ways:\n\n"
			<< "./prog -sort -bubble inputFile outputFile\n"
			<< "./prog -sort -selection inputFile outputFile\n"
			<< "./prog -sort -insertion inputFile outputFile\n"
			<< "./prog -sort -quick inputFile outputFile\n"
			<< "./prog -sort -quick3 inputFile outputFile\n"
			<< "./prog -sort -merge inputFile outputFile\n"
			<< "./prog -sort -all inputFile outputFile\n"
			<< "Option explainations:\n"
			<< "\t-bubble to time bubble sort and store all timing results in outputFile\n"
			<< "\t-selection to time selection sort and store all timing results in outputFile\n"
			<< "\t-insertion to time insertion sort and store all timing results in outputFile\n"
			<< "\t-quick to time quick sort and store all timing results in outputFile\n"
			<< "\t-quick3 to time quick3 sort  and store all timing results in outputFile\n"
			<< "\t-merge to time merge sort  and store all timing results in outputFile\n"
			<< "\t-all to time all of the sorts and store all timing results in outputFile\n"
			<< "\tinputFile must be file created by a NumberFileGenerator\n"
			<< "\toutputFile must be to a valid path. It will hold the timing results\n";
}

bool SortDriver::isFileAccessible(string fileName)
{
	ifstream myFile(fileName);
	if(myFile.good())
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool SortDriver::isSortValid(string sortParameter)
{
	if(sortParameter.compare("-bubble")==0 || sortParameter.compare("-selection")==0 || sortParameter.compare("-insertion")==0 || sortParameter.compare("-quick")==0 || sortParameter.compare("-quick3")==0 || sortParameter.compare("-merge")==0 || sortParameter.compare("-bubble")==0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void SortDriver::copyArray(int original[], int copy[], int size)
{
	for(int i=0; i<size; i++)
	{
		copy[i]= original[i];
	}

}

bool SortDriver::areParametersValid(std::string sortName, std::string inputFileName)
{
	if(isSortValid(sortName)==false)
	{
		std::cout<<"Invalid sort option\n";
		return false;
	}
	else if(isFileAccessible(inputFileName)==false)
	{
		std::cout<<"Invalid file name\n";
		return false;
	}
	return true;
}



int* SortDriver::createArray(ifstream& inputFile, int size)
{
	int* arr = new int[size];
	for(int i=0; i< size; i++)
	{
		inputFile>> arr[i];
	}
	return arr;
}


int SortDriver::getFileCount(std::ifstream& inputFile)
{
	int temp;
	inputFile>>temp;
	return temp;
}


void SortDriver::run(int argc, char** argv)
{
	if(areParametersValid(argv[2], argv[3]))
	{
		string inputAsString(argv[2]);
		string myInputFile(argv[3]);
		string myOutputFile(argv[4]);
		ifstream input(myInputFile);
		ofstream output(myOutputFile);
		int size = getFileCount(input);
		int* arr = createArray(input,size);
		if(strcmp( argv[2], "-bubble") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			output << "bubble " <<" " << size << " "<< timeTaken << endl;
		}
		else if(strcmp( argv[2], "-selection") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::selectionSort,arr, size);
			output << "selection"<<" " << size <<" " << timeTaken  << endl;
		}
		else if(strcmp( argv[2], "-insertion") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::insertionSort,arr, size);	
			output << "insertion"<<" "  << size <<" " << timeTaken << endl;
		}
		else if(strcmp( argv[2], "-quick") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSort,arr, size);
			output << "quick" <<" " << size<<" "  << timeTaken << endl;
		}
		else if(strcmp( argv[2], "-quick3") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian,arr, size);
			output << "quick3" <<" " << size <<" " << timeTaken <<  endl;		
		}
		else if(strcmp( argv[2], "-merge") == 0)
		{
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::mergeSort,arr, size);
			output << "merge" <<" " << size <<" " << timeTaken<< endl;
		}
		else if(strcmp( argv[2], "-all") == 0)
		{
			int arr2[size];
			int arr3[size];
			int arr4[size];
			int arr5[size];
			int arr6[size];
			copyArray(arr,arr2,size);
			copyArray(arr,arr3,size);
			copyArray(arr,arr4,size);
			copyArray(arr,arr5,size);
			copyArray(arr,arr6,size);
			double timeTaken = Sorts<int>::sortTimer(Sorts<int>::bubbleSort, arr, size);
			output << "bubble " << size << timeTaken << endl;
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::selectionSort, arr, size);
			output << "selection"<< size << timeTaken  << endl;
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::insertionSort,arr, size);	
			output << "insertion" << size << timeTaken << endl;
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSort,arr, size);
			output << "quick" << size << timeTaken << endl;
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::quickSortWithMedian,arr, size);
			output << "quick3" << size << timeTaken <<  endl;	
			timeTaken = Sorts<int>::sortTimer(Sorts<int>::mergeSort,arr, size);
			output << "merge" << size << timeTaken<< endl;
		}
		else
		{
			printHelpMenu();
		}
	}
}

