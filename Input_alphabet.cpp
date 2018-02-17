//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//input_alphabet.cpp

#include "Input_alphabet.h"
#include <vector>
#include <fstream>
#include <iostream>
#include "upperCase.h"
using namespace std;

void Input_alphabet::Load(ifstream &definition, bool &valid)
{
    string value;
    int infloop = 0;
    while(infloop == 0)
    {
        if(definition >> value)
        {
            if((value == "TAPE_ALPHABET:") && ((int)alphabet.size() == 0))
            {
                cout << "Illegal Input Alphabet.\n";
                valid = false;
                return;
            }
            else if(value == "TAPE_ALPHABET:")
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
                            cout << "Illegal Input Alphabet, duplicate.\n";
                            valid = false;
                            return;
                        }
                    }
                        alphabet.push_back(value[0]);
                }
                else
                {
                    cout << "Illegal Input Alphabet.\n";
                    valid = false;
                    return;
                }
            }
        }
        else
        {
            cout << "Missing keyword after Input Alphabet.\n";
            valid = false;
            return;
        }
    }
}
void Input_alphabet::View()const
{
cout << "Σ = {";

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
int Input_alphabet::Size()const
{
    return alphabet.size();
}
char Input_alphabet::Element(int index) const
{
    return alphabet[index];
}
bool Input_alphabet::Is_element(char value) const
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