/**
*	@file : MazeCreationException.cpp
*	@author :  Luke Weaver
*	@date : 2015.18.11
*	@brief: to create an exception if the user runs into an error
*/
#include "MazeCreationException.h"
MazeCreationException :: MazeCreationException(const char* message) : std :: runtime_error(message)
{
}
