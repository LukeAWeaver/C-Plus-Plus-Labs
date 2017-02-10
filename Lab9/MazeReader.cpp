/**
*	@file : MazeReader.cpp
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: to create a maze
*/
#include "MazeReader.h"
using namespace std;	
MazeReader:: MazeReader(string file) throw (MazeCreationException)
{
	try
	{
		m_filename.open(file);
	}
	catch(MazeCreationException& e)
	{
		throw MazeCreationException(e.what());
	}
	try
	{	
		readMaze();
	}
	catch(MazeCreationException& e)
	{
		throw MazeCreationException(e.what());
	}
}	
MazeReader::~MazeReader()
{
	m_filename.close();
	delete m_maze;
}
const char* const* MazeReader::getMaze() const
{
	return(m_maze);
}
int MazeReader::getCols() const
{
	return m_cols;
}
int MazeReader::getRows() const
{
	return m_rows;
}
int MazeReader::getStartCol() const
{
	return m_startcol;
}
int MazeReader::getStartRow() const
{
	return m_startrow;
}
void MazeReader::readMaze()	throw (MazeCreationException)
{	

		try
		{

			getline(m_filename, m_read1);
			m_stoc1=m_read1[0];
			m_stoc2=m_read1[2];
			m_rows=m_stoc1 - 48;
			m_cols=m_stoc2 - 48;
			getline(m_filename,m_read1);
			m_stoc1=m_read1[0];
			m_stoc2=m_read1[2];
			m_startrow=m_stoc1-48;
			m_startcol=m_stoc2-48;

		}
		catch(MazeCreationException& e)
		{
			throw MazeCreationException("invalid maze");
		}

		if(m_rows<1||m_cols<1||m_startrow < 0 || m_startcol < 0 || m_startrow > m_rows || m_startcol > m_cols)
		{
			throw MazeCreationException("Invalid maze.");
		}
		else
		{
			try
			{
				m_maze = new char*[m_rows];
				for(int i =0; i<m_rows; i++)
				{
					m_maze[i] = new char[m_cols];
				}
				for(int j = 0; j<m_cols+2; j++)
				{
					m_filename >> m_read1;
					for(int k=0; k<m_cols; k++)
					{
						m_maze[j][k] = char(m_read1[k]);
					}
				}
			}
			catch(MazeCreationException& e)
			{
				throw MazeCreationException("Invalid Maze");
			}
		}
}
/*
					getline(m_filename,m_read1);
		if(file=="maze.txt" || file=="noExit.txt" || file=="badStart.txt" ||file=="badCols.txt" ||file=="badRows.txt")
		{
			m_filename=file;	
		}

				cout <<"Starting position: "<< m_startrow << "," << m_startcol << endl;
				cout <<"Size: " << m_rows << "," << m_cols << endl;
						m_filename >> m_placeholder;
						m_maze[i][j] = m_placeholder; 
MazeReader:: MazeReader(string file) throw (MazeCreationException) : m_filename(file)


*/

