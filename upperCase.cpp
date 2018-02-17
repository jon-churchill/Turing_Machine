//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//upperCase.cpp

#include "upperCase.h"
#include <iostream>
#include <string>
#include <ctype.h>
using namespace std;


string upperCase::uppercase(string value)
{

for(unsigned int index = 0; index < value.length(); index++)
     {  
          value[index] = toupper(value[index]);   
     }
return value;
}


char upperCase::uppercase(char value)
{
	char returnvalue = toupper(value);
	return returnvalue;
}