/**
*	@file : MazeCreationException.h
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: to create an exception
*/
#ifndef MAZECREATIONEXCEPTION_H
#define MAZECREATIONEXCEPTION_H
#include <stdexcept>
#include <iostream>
using namespace std;
class MazeCreationException : public std::runtime_error
{
    public:
          /**
          * @post Creates an exception with the message
          */
          MazeCreationException(const char* message);
};
#endif
