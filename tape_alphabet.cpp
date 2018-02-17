//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//tape.cpp

#include "tape_alphabet.h"
#include "upperCase.h"
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;


void tape_alphabet::Load(ifstream &definition, bool &valid)
{
    string value;
    int infloop = 0;
    while(infloop == 0)
    {
        if(definition >> value)
        {
            if((value == "TRANSITION_FUNCTION:") && ((int)alphabet.size() == 0))
            {
                cout << "Illegal Tape Alphabet.\n";
                valid = false;
                return;
            }
            else if(value == "TRANSITION_FUNCTION:")
            {
                return;
            }
            else
            {
            
                if((value.size() == 1) && (value[0] != '\\') && (value[0] != '[') && (value[0] != ']') && (value[0] != '<')
                                          && (value[0] != '>') && (value[0] >= '!') && (value[0] <= '~'))
                {
                    for(int index = 0; index < (int)alphabet.size(); index++)
                    {
                        if(alphabet[index] == value[0])
                        {
                            cout << "Illegal Tape Alphabet, duplicate.\n";
                            valid = false;
                            return;
                        }
                    }

                    alphabet.push_back(value[0]);
                }
                else
                {
                    cout << "Illegal Tape Alphabet.\n";
                    valid = false;
                    return;
                }
            }
        }
        else
        {
            cout << "Missing keyword after Tape Alphabet.\n";
            valid = false;
            return;
        }
    }
}
void tape_alphabet::View()const
{

cout << "Г = {";

    for(unsigned int index=0; index < alphabet.size(); index++)
    {
        if(alphabet.size()-1 != index)
        {
            cout << alphabet[index] <<",";
        }
        else
        {
            cout << alphabet[index] <<"}\n"<<endl;
        }

    }
}
bool tape_alphabet::Is_element(char value)
{
    for(int index = 0; index < (int)alphabet.size(); index++)
    {
        if(alphabet[index] == value)
        {
            return true;
        }
    }
    return false;
}