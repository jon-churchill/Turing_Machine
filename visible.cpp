//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//visible.cpp

#include "visible.h"
#include <string>

using namespace std;

string visible(string value)
{
	const string lambda("\\");
	if(value.empty())
	{
		value = lambda;
	}
	return value;
}
