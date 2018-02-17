//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//state.h

#ifndef STATE_H
#define STATE_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class State
{
  private:
    vector<string> names;
  public:
    void Load(ifstream &definition, bool &valid);
    void View()const;
    bool Is_element(string value);
};
#endif