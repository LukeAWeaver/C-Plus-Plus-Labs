/**
*	@file : Position.h
*	@author :  Luke Weaver
*	@date : 2015.11.11
*	@brief: to declare position variables
*/
#ifndef POSITION_H
#define POSITION_H
class Position
{
	public:
	/**
	* @post Position created with row and col values set.
	*/
	Position(int row, int col);

	Position();
	/**
	*	@return row value
	*/
	int getRow() const;

	/**
	*	@return col value
	*/
	int getCol() const;
	private:
	int p_row;
	int p_col;

};
#endif
