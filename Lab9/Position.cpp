/**
*	@file : Position.cpp
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: to determine position in maze
*/
#include "Position.h"
using namespace std;
Position::Position(int row, int col)
{
	p_row = row;
	p_col = col;
}
	/**
	*	@return row value
	*/
int Position:: getRow() const
{
	return p_row;
}
	/**
	*	@return col value
	*/
int Position:: getCol() const
{
	return p_col;
}
Position::Position()
{
	p_row=0;
	p_col=0;
}
