#ifndef CLASSNAME_H
#define CLASSNAME_H
template <typename T>
 class className
{
void randommethod();
T method();

};
#include "className.hpp"
#endif



//.hpp file
template <typename T>
className<T>::randommethod()
{}
template <typename T>
T className<T>:: method()
{}
