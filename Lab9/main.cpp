/**
*	@file : main.cpp
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: allow user to create a maze
*/
#include <iostream>
#include <string>
#include "Test.h"
#include <fstream>
#include "MazeWalker.h"
#include "MazeReader.h"
#include "MazeCreationException.h"
using namespace std;
int main(int argc, char** argv)
{
    	Search mySearch;
	string choice = argv[1];
	Test mytest;
	if(argc == 2 && choice=="-test")
	{
		mytest.runTests();
	}

	else if(argc>=3 && choice=="-dfs")
	{
		string file = argv[2];
		try
		{
			MazeReader* myMazeReader = new MazeReader(file);
		}
		catch(std::exception& e)
		{
			cout << e.what();
		}	
		mySearch = Search::DFS; 
	
	}
	else if(argc >= 3 && choice=="-bfs")
	{
		string file = argv[2];
		try
		{
			MazeReader* myMazeReader = new MazeReader(file);
		}
		catch(std::exception& e)
		{
			cout << e.what();
		}	
		mySearch = Search::DFS; 
	}
	else
	cout << "invalid option" << endl;
}
