//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//final_state.h

#ifndef FINAL_STATE_H
#define FINAL_STATE_H

#include <string>
#include <vector>
#include <fstream>
using namespace std;

class final_state
{
  private:
    vector<string> names;
  public:
    void Load(ifstream &definition, bool &valid);
    void View()const;
    bool Is_element(string value);
    int size()const;
    string Element(int index);

};
#endif