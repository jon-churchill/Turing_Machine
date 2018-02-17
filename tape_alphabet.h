//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//tape.h

#ifndef TAPE_ALPHABET_H
#define TAPE_ALPHABET_H

#include <vector>
#include <fstream>
using namespace std;

class tape_alphabet
{
  private:
    vector<char> alphabet; 
  public:
    void Load(ifstream &definition, bool &valid);
    void View()const;    
    bool Is_element(char value);
};
#endif