/**
*	@file : SortDriver.h
*	@author : Luke Weaver
*	@date : 11-03-2015
*	Purpose: declare methods for SortDriver
*/
#ifndef SORTDRIVER_H
#define SORTDRIVER_H
#include <fstream>
#include <string>
using namespace std;

class SortDriver
{
	public:
	/**
	*  @pre valid 2-D array and the arguments contained within are valid.
	*  @post If the arguments are valid, a number file is created following those specifications.Otherwise, the help menu is printed and no files are created.
	*  @return none
	*/
	static void run(int argc, char** argv);
	/**
	*  @pre none
	*  @post prints help menu
	*  @return none
	*/
	static void printHelpMenu();
	private:
	/**
	*  @pre a string
	*  @post The input file was created by a NumberFileGenerator.
	*  @return none
	*/
	static bool isFileAccessible(std::string fileName);
	/**
	*  @pre a string
	*  @post none
	*  @return True if the sort parameter matches a valid one (see help menu).
	*/
	static bool isSortValid(std::string sortParameter);
	/**
	*  @pre none
	*  @post none
	*  @return True is the file specified by inputFileName exists and the sort parameter is valid, false otherwise.
	*/
	static bool areParametersValid(std::string sortName, std::string inputFileName);
	/**
	*  @pre The input file was created with the Number File Generator
	*  @post The first line of the file is read in, containing the count.
	*  @return Returns how many numbers are in the file.
	*/
	static int getFileCount(std::ifstream& inputFile);
	/**
	*  @pre The input file was created with the Number File Generator, the size was read in, and that size if correct.
	*  @post The remainder of input file numbers are read in. File is NOT closed.
	*  @return A pointer to a new array containing the values from the input file.
	*/
	static int* createArray(std::ifstream& inputFile, int size);
	/**
	*  @pre Original and copy are valid arrays of the correct size.
	*  @post All values from original are copied into copy.
	*  @return none
	*/
	static void copyArray(int original[], int copy[], int size);
};
#endif
