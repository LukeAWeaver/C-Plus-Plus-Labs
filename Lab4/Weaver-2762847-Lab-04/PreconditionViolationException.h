/**
*	@file : PreconditionViolationException.h
*	@author :  Luke Weaver
*	@date : 2015.10.06
*	@brief: handles exceptions 
*/

#ifndef PRECONDITIONVIOLATIONEXCEPTION
#define PRECONDITIONVIOLATIONEXCEPTION
#include <stdexcept>
class PreconditionViolationException : public std::runtime_error
{
public:
	/**
	*  @pre a fault in code
	*  @post exception handled 
	*  @return error messege
	*/
	PreconditionViolationException(const char* msg);
};
#endif
