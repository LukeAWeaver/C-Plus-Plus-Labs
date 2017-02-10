/**
*	@file : MazeReader.h
*	@author :  Luke Weaver
*	@date : 2015.11.11
*	@brief: to declare variabes to traverse through a maze
*/
#ifndef MAZEREADER_H
#define MAZEREADER_H
#include <fstream>
#include "MazeCreationException.h"
#include <string>
#include <iostream>
#include <functional>
using namespace std;
class MazeReader
{
	public:
	/**
	*	@post A MazeReader is created. A 2D char array is allocated with the maze information.
	*	@throws MazeCreationExecption
	*
	*/
	MazeReader(string file) throw (MazeCreationException);

	/**
	*	@post The maze is deallocated.
	*/
	~MazeReader();

	/**
	*	@pre the file was formatting and read in correctly
	*	@return Returns pointer to the maze
	*/
	const char* const* getMaze() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of columns listed in the file
	*/
	int getCols() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the number of rows listed in the file
	*/
	int getRows() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting column
	*/
	int getStartCol() const;

	/**
	*	@pre the file was formatted and read in correctly
	*	@returns the starting row
	*/
	int getStartRow() const;

	int m_startrow,m_startcol;
	string m_read1;
	ifstream m_filename;
	char m_stoc1,m_stoc2;
	char** m_maze;
	int m_cols;
	int m_rows;
	char m_placeholder;
	protected:
	/**
	*	@pre the file is properly formatted
	*	@post the characters representing the maze are stores
	*/
	void readMaze()	throw (MazeCreationException);	

};
#endif
