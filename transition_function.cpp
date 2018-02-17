//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//transitions_function.cpp


#include "transition_function.h"
#include "transition.h"
#include "direction.h"
#include "upperCase.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

void transition_function::load(ifstream &definition, bool &valid)
{
    string value;
    string tempOne;
    string tempTwo;
    string tempThree;
    string tempFour;
    string tempFive;
    int infloop = 0;
    while(infloop == 0)
    {
        if(definition >> value)
        {
            if(value == "INITIAL_STATE:")
            {
                return;
            }
            else
            {
                tempOne = value;
                definition >> tempTwo;
                definition >> tempThree;
                definition >> tempFour;
                definition >> tempFive;

                for(int index = 0; index < (int)tempOne.size(); index++)
                {
                    if((tempOne[index] != '\\') && (tempOne[index] != '[') && (tempOne[index] != ']') && (tempOne[index] != '<')
                                          && (tempOne[index] != '>') && (tempOne[index] >= '!') && (tempOne[index] <= '~'))
                    {

                    }
                    else
                    {
                        cout << "Illegal Transition Function.\n";
                        valid = false;
                        return;
                    }
                }

                for(int indexTwo = 0; indexTwo < (int)tempThree.size(); indexTwo++)
                {
                    if((tempThree[indexTwo] != '\\') && (tempThree[indexTwo] != '[') && (tempThree[indexTwo] != ']') && (tempThree[indexTwo] != '<')
                                          && (tempThree[indexTwo] != '>') && (tempThree[indexTwo] >= '!') && (tempThree[indexTwo] <= '~'))
                    {

                    }
                    else
                    {
                        cout << "Illegal Transition Function.\n";
                        valid = false;
                        return;
                    }
                }
            
                if((tempTwo.size() == 1) && (tempTwo[0] != '\\') && (tempTwo[0] != '[') && (tempTwo[0] != ']') && (tempTwo[0] != '<')
                                          && (tempTwo[0] != '>') && (tempTwo[0] >= '!') && (tempTwo[0] <= '~'))
                {
                    
                }
                else
                {
                    cout << "Illegal Transition Function.\n";
                    valid = false;
                    return;
                }

                if((tempFour.size() == 1) && (tempFour[0] != '\\') && (tempFour[0] != '[') && (tempFour[0] != ']') && (tempFour[0] != '<')
                                          && (tempFour[0] != '>') && (tempFour[0] >= '!') && (tempFour[0] <= '~'))
                {

                }
                else
                {
                    cout << "Illegal Transition Function.\n";
                    valid = false;
                    return;
                }

                if((tempFive.size() == 1) && (tempFive[0] != '\\') && (tempFive[0] != '[') && (tempFive[0] != ']') && (tempFive[0] != '<')
                                          && (tempFive[0] != '>') && (tempFive[0] >= '!') && (tempFive[0] <= '~'))
                {

                }
                else
                {
                    cout << "Illegal Transition Function.\n";
                    valid = false;
                    return;
                }
                upperCase ucobj;
                transition transition1(tempOne, tempTwo[0], tempThree, tempFour[0], ucobj.uppercase(tempFive[0]));

                transitions.push_back(transition1);
            }
        }
        else
        {
            cout << "Missing keyword after Transition Function.\n";
            valid = false;
            return;
        }
    }
}

void transition_function::view()const
{
//view a transition
    for(unsigned index=0; index < transitions.size(); index++)
    {
        cout <<"δ(" <<transitions[index].source_state() << "," <<transitions[index].read_character()<< ")=(";
        cout <<transitions[index].destination_state()<< ","<<transitions[index].write_character()<< ",";
        cout <<transitions[index].move_direction() << ")\n";

    }
cout<<endl;
}

int transition_function::size()const
{
//how many transitions there are

return transitions.size();

}

string transition_function::source_state(int index)const
{
//this source state is from transition class
return transitions[index].source_state();
}

char transition_function::read_character(int index)const
{
return transitions[index].read_character();
}

string transition_function::destination_state(int index)const
{
return transitions[index].destination_state();
}

bool transition_function::is_defined_transition(string source_state, char read_character, string &destination_state, char &write_character,direction &move_direction)const
{
    for(unsigned int index=0; index < transitions.size(); index++)
    {

        if((transitions[index].source_state() == source_state) && (transitions[index].read_character() == read_character))
        {
            destination_state = transitions[index].destination_state();
            write_character = transitions[index].write_character();
            move_direction = transitions[index].move_direction();
            return true;
        }
    }
    
  return false;
}

bool transition_function::is_source_state(string state)const
{
    for(int index = 0; index < (int)transitions.size();index++)
    {
        if(state == transitions[index].source_state())
        {
            return true;
        }
    }
    return false;
}