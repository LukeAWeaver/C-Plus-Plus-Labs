/**
*	@file : PreconditionViolationException.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.06
*	@brief: handles exceptions 
*/
#include "PreconditionViolationException.h"

PreconditionViolationException::PreconditionViolationException(const char* msg): std::runtime_error(msg)
{

}
