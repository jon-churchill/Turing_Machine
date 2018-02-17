//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//input_alphabet.h

#ifndef INPUT_ALPHABET_H
#define INPUT_ALPHABET_H

#include <vector>
#include <fstream>
using namespace std;

class Input_alphabet
{
  private:
    vector<char> alphabet; 
  public:
    void Load(ifstream &definition, bool &valid);
    void View()const;
    int Size()const;
    char Element(int index)const;
    bool Is_element(char value)const;
};
#endif