//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//final_state.cpp


#include "final_state.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

void final_state::Load(ifstream &definition, bool &valid)
{
    string value;
    int infloop = 0;
    while(infloop == 0)
    {
        if(definition >> value)
        {
            for (int index = 0; index < (int)value.size(); index++)
            {
                if((value[index] != '\\') && (value[index] != '[') && (value[index] != ']') && (value[index] != '<')
                                          && (value[index] != '>') && (value[index] >= '!') && (value[index] <= '~'))
                {
                }
                else
                {
                    cout << "Illegal Final State name.\n";
                    valid = false;
                    return;
                }
            }
            names.push_back(value);
        }
        else
        {
            infloop = 1;
        }
    }
}
void final_state::View()const
{

  cout << "F = {";
    for(unsigned int index =0; index < names.size(); index++)
    {
        if(names.size()-1 != index)
        {
             cout << names[index] << ",";
        }
         else
        {
            cout << names[index];
        }
    }
    cout <<"}\n"<<endl;
}
int final_state::size()const
{
    return names.size();
}
string final_state::Element(int index)
{
    return names[index];
}
bool final_state::Is_element(string value)
{
    for(int index = 0; index < (int)names.size(); index++)
    {
        if(names[index] == value)
        {
            return true;
        }
    }
    return false;
}

