//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//State.cpp

#include "State.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "upperCase.h"
using namespace std;

void State::Load(ifstream &definition, bool &valid)
{
    string value;
    int infloop = 0;

    while(infloop == 0)
    {
        if(definition >> value)
        {
            if((value == "INPUT_ALPHABET:") && ((int)names.size() == 0))
            {
                cout << "Illegal States.\n";
                valid = false;
                return;
            }
            else if(value == "INPUT_ALPHABET:")
            {
                valid = true;
                return;
            }
            else
            {
                for (int index = 0; index < (int)value.size(); index++)
                {
                    if((value[index] != '\\') && (value[index] != '[') && (value[index] != ']') && (value[index] != '<')
                                              && (value[index] != '>') && (value[index] >= '!') && (value[index] <= '~'))
                    {
                    }
                    else
                    {
                        cout << "Illegal State name.\n";
                        valid = false;
                        return;
                    }
                }

                for(int indexVec = 0; indexVec < (int)names.size(); indexVec++)
                {
                    if(names[indexVec] == value)
                    {
                        cout << "Illegal State name, duplicate.\n";
                        valid = false;
                        return;
                    }
                }
                names.push_back(value);
                

            }
        }
        else
        {
            cout << "Missing keyword after States.\n";
            valid = false;
            return;
        }
    }

}
void State::View()const
{
    cout << "Q = {";
    for(int index = 0; index < (int)names.size(); index++)
    {
        if((int)names.size()-1 != index)
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
bool State::Is_element(string value)
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

