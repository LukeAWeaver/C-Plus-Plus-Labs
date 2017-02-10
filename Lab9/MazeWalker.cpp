/**
*	@file : MazeWalker.cpp
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: to traverse through a maze
*/
#include "MazeWalker.h"
using namespace std;

MazeWalker::MazeWalker(const char* const* mazePtr, int startRow, int startCol, int rows, int cols, Search searchChoice)
{
	x=1;
	m_visited = new int*[rows]; //tracks maze movement
	for(int i = 0; i<rows; i++)
	{
		m_visited[i] = new int[cols];
		for(int j = 0; j<cols; j++)
		{
			m_visited[i][j] = 0; //set everything to not visited
		}
	}
	m_searchType=searchChoice;
	m_startrow = startRow;
	m_startcol = startCol;	
	m_visited[startRow][startCol] = x; //sets first position to traversed
	Position m_curPos(m_startrow,m_startcol);
	Position m_startPos(m_startrow,m_startcol);
	m_rows = rows;
	m_cols = cols;
	m_maze = mazePtr; //char version of maze
}
MazeWalker::~MazeWalker()
{
	for(int i = 0; i< m_rows; i++)
	{
		delete [] m_visited[i];
	}
	delete [] m_visited;
	while((m_moveQueue.empty() || m_moveStack.empty())==false)
	{
		m_moveStack.pop();
		m_moveQueue.pop();
	}

}
bool MazeWalker::walkMaze()
{
	bool exitReached = false;
	bool notDone = true;
	while(notDone==true)
	{
		storeValidMoves();
		if(isGoalReached()) //checking that the goal is reached
		{
			notDone = false;
			exitReached = true;
		}
		else
		{
			if(m_searchType==Search::DFS)
			{
				if(m_moveStack.empty()==true) //there are no more moves left then exit loop
				{
					notDone = false;
				}
				else //there are moves left so continue
				{
					move(m_moveStack.top());
				}		
			}
			else
			{		
				if(m_moveQueue.empty()==true)
				{
					notDone = false;
				}
				else
				{
					move(m_moveQueue.front());
				}		

			}
		}

	}
	if(exitReached==true)
	{
		return true;
	}
	else
	{
		return false;
	}
}
const int* const* MazeWalker::getVisited() const
{
	return m_visited;
}

int MazeWalker::getVisitedRows() const
{
	return m_rows;
}

int MazeWalker:: getVisitedCols() const
{
	return m_cols;
}	
const char* const* MazeWalker:: getMaze() const
{
	return m_maze;
}
void MazeWalker::storeValidMoves()
{
	if((m_curPos.getRow()-1)>=0) //^
	{
		if((m_visited[m_curPos.getRow()-1][m_curPos.getCol()])==0) //^ hasn't been visited
		{
			if(m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='P' || m_maze[m_curPos.getRow()-1][m_curPos.getCol()]=='E')
			{
				if(m_searchType==Search::DFS)
				{
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else
				{
					Position temp(m_curPos.getRow()-1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}
	}
	if ((m_curPos.getCol()+1)<m_cols)	//>
	{
		if((m_visited[m_curPos.getRow()][m_curPos.getCol()+1])==0) //> hasn't been visited
		{
			if(m_maze[m_curPos.getRow()][(m_curPos.getCol()+1)]=='P' ||m_maze[m_curPos.getRow()][m_curPos.getCol()+1]=='E')
			{
	
				if(m_searchType==Search::DFS)
				{	
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveStack.push(temp);
				}
				else
				{
					Position temp(m_curPos.getRow(), m_curPos.getCol()+1);
					m_moveQueue.push(temp);
				}
			}
		}
	}
	if((m_curPos.getRow()+1)<m_rows) //v
	{
		if((m_visited[m_curPos.getRow()+1][m_curPos.getCol()])==0) // v hasn't been visited
		{
			if(m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='P' || m_maze[m_curPos.getRow()+1][m_curPos.getCol()]=='E')
			{
				if(m_searchType==Search::DFS)
				{
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveStack.push(temp);
				}
				else
				{
					Position temp(m_curPos.getRow()+1, m_curPos.getCol());
					m_moveQueue.push(temp);
				}
			}
		}
	}
	if((m_curPos.getCol()-1)>=0) //<
	{
		if((m_visited[m_curPos.getRow()][m_curPos.getCol()-1])==0) // < hasn't been visited 
		{
			if(m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='P' || m_maze[m_curPos.getRow()][m_curPos.getCol()-1]=='E')
			{
				if(m_searchType==Search::DFS)
				{
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveStack.push(temp);
				}
				else
				{
					Position temp(m_curPos.getRow(), m_curPos.getCol()-1);
					m_moveQueue.push(temp);
				}
			}
		}
	}
}
void MazeWalker::move(Position& p)
{
	x++;
	Position m_curPos(p.getRow(),p.getCol()); //sets current position to the position that was stored on queue or stack
	m_visited[m_curPos.getRow()][m_curPos.getCol()] = x; //sets current position as visited
	if(m_searchType==Search::DFS)
	{
		m_moveStack.pop(); //removes top of stack
	}
	else
	{
		m_moveQueue.pop(); //removes first in queue
	}
}
bool MazeWalker::isGoalReached() const
{
	bool isExitReached = false; 
	if(m_maze[m_curPos.getRow()][m_curPos.getCol()] == 'E')
		{
			isExitReached = true;
		}
	return isExitReached;
}

