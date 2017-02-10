/**
*	@file : CyberChicken.cpp
*	@author :  Luke Weaver
*	@date : 2015.10.21
*	@brief: driver for cyberchicken
*/
#include "CyberChicken.h"
using namespace std;
CyberChicken::CyberChicken()
{
	m_name = "Cyber Chicken";
	m_sound= "Resistance is futile";
	m_eggs=0;
}
CyberChicken::~CyberChicken()
{
	cout<< "CyberChicken Destructor called." <<endl;
}
int CyberChicken:: getCyberEggs() const
{
	return m_eggs;
}
void CyberChicken:: setCyberEggs(int eggs)
{
	m_eggs = eggs;
}

