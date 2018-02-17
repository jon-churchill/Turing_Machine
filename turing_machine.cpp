//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//turing_machine.cpp

#include "turing_machine.h"
#include "Tape.h"
#include "Input_alphabet.h"
#include "tape_alphabet.h"
#include "transition_function.h"
#include "State.h"
#include "final_state.h"
#include "upperCase.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
using namespace std;

turing_machine::turing_machine(string definition_file_name)
{
    
    help = false;
    string definitionFile = definition_file_name + ".def";
    string stringFile = definition_file_name + ".str";
    ifstream file(definitionFile.c_str());
    string line;
    unsigned int found;
    unsigned int npos = -1;
    int filePosition = 0;
    upperCase upobj;
    valid = true;
    number_of_transitions = 0;
    max_tape_head = 32;
    used = false;
    rejected = false;
    accepted = false;
    operating = false;
    max_number_transitions = 1;
    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            string tempFullLine = upobj.uppercase(line);
            string temp2 = line;
            string temp3 = line;
            string goodTest = "";

            found = tempFullLine.find("STATES:");
            if (found != npos)
            {
                for(int index = 0; index < (int)found; index++)
                {
                    description += line[index];
                }

                filePosition += found + 7;
                break;
            }
            else
            {
                description += line + "\n";
            }

            filePosition = file.tellg();
        }

        file.seekg(filePosition);
        if(valid == true)
        {
            states.Load(file, valid);
        }
        if(valid == true)
        {
            input_alphabet.Load(file, valid);
        }
        if(valid == true)
        {
            tape_alphabets.Load(file, valid);
        }
        if(valid == true)
        {
            transition_functions.load(file, valid);
        }
        if(valid == true)
        {
            file >> initial_state;
            for (int index = 0; index < (int)initial_state.size(); index++)
            {
                if((initial_state[index] != '\\') && (initial_state[index] != '[') && (initial_state[index] != ']') && (initial_state[index] != '<')
                                          && (initial_state[index] != '>') && (initial_state[index] >= '!') && (initial_state[index] <= '~'))
                {
                }
                else
                {
                    cout << "Illegal Initial State.\n";
                    valid = false;
                }
            }
            string blankCharText = "";
            file >> blankCharText;
            if(upobj.uppercase(blankCharText) != "BLANK_CHARACTER:")
            {
                valid = false;
            }
        }
        if(valid == true)
        {
            tape.load(file, valid);
        }
        if(valid == true)
        {
            final_states.Load(file, valid);
        }
        file.close();

        if (valid == true)
        {
            if(!tape_alphabets.Is_element(tape.blank_character()))
            {
                cout << "Illegal Blank Character.\n";
                valid = false;
                return;
            }
            if(input_alphabet.Is_element(tape.blank_character()))
            {
                cout << "Illegal Blank Character.\n";
                valid = false;
                return;
            }
            for(int indexInput = 0; indexInput < (int)input_alphabet.Size(); indexInput++)
            {
                if(!tape_alphabets.Is_element(input_alphabet.Element(indexInput)))
                {
                    cout << "Illegal Input Alphabet.\n";
                    valid = false;
                    return;
                }
            }
            if(!states.Is_element(initial_state))
            {
                cout << "Illegal Initial State.\n";
                valid = false;
                return;
            }
            for(int indexFinal = 0; indexFinal < (int)final_states.size(); indexFinal++)
            {
                if(!states.Is_element(final_states.Element(indexFinal)))
                {
                    cout << "Illegal Final State.\n";
                    valid = false;
                    return;
                }
            }
            for(int indexTrans = 0; indexTrans < (int)final_states.size(); indexTrans++)
            {
                if(transition_functions.is_source_state(final_states.Element(indexTrans)))
                {
                    cout << "Illegal Final State, transition.\n";
                    valid = false;
                    return;
                }
            }
        }

    }
        
    ifstream strFile;
    strFile.open(stringFile.c_str());
    if(!strFile)
    {
        cout << "Failure opening the string file, creating one" <<endl;
    }
    else
    {
        string inputstringread ="";
        while(getline(strFile, inputstringread))
        {
            if(inputstringread == "\\")
            {
                inputstrings.push_back("");
            }
            else
            {
                inputstrings.push_back(inputstringread);
            }           
        }
        strFile.close();
    }            
    
}
void turing_machine::write(string definition_file_name)
{
    string stringFile = definition_file_name + ".str";
    ofstream strFile;
    strFile.open(stringFile.c_str(),ios::out | ios::trunc);
    if(!strFile)
    {
        cout << "Failure opening the string file, creating one" <<endl;
    }
    else
    {
        for(int index = 0; index < (int)inputstrings.size(); index++)
        {
            if(index != (int)inputstrings.size() - 1)
            {
                if("" != inputstrings[index])
                {
                    strFile << inputstrings[index] << "\n";
                }
                else
                {
                    strFile << "\\" << "\n";
                }
                
            }
            else
            {
                if("" != inputstrings[index])
                {
                    strFile << inputstrings[index];
                }
                else
                {
                    strFile << "\\";
                }
            }
        }
        strFile.close();
    }      
}
void turing_machine::view_definition()const
{    
    cout<<description<<endl;      
    states.View();
    input_alphabet.View();
    tape_alphabets.View();
    transition_functions.view();
    cout<<"q0 = "<< initial_state <<endl;
    tape.view();
    final_states.View();
}
void turing_machine::view_inputstrings()const
{    
    for(unsigned int index=0; index < inputstrings.size(); index++)
    {        
        if(inputstrings[index] == "")
        {
            cout << index+1 << ": \\" << endl;
        }
        else
        {
            cout << "[" << index+1 << "] "<< inputstrings[index]<<endl;
        }
    }
}
bool turing_machine::deletestring(int linenum)
{
    if(linenum < 1 || linenum > (int)inputstrings.size())
    {       
        cout << "invalid input" << endl;
        return false; 
    }    
    else
    {
        inputstrings.erase(inputstrings.begin()+linenum - 1);
        return true;
    }
}
bool turing_machine::insert_string(string insertstring)
{
    bool check = false;
    if(is_valid_input_string(insertstring) == false)
    {
        return false;
    }
    for(int index = 0; index < (int)inputstrings.size(); index++)
    {
        if(inputstrings[index] == insertstring)
        {
            check = true;
        }
    }
    if(check == false)
    {
        if(insertstring == "\\")
        {
            inputstrings.push_back("");
        }
        else
        {
            inputstrings.push_back(insertstring);
        }
        
        return true;
    }
    else
    {
        cout << "that input string already exists" << endl;
        return false;
    }
    
}
void turing_machine::set_transitions(unsigned long maxtrans)
{
    max_number_transitions = maxtrans;
}
void turing_machine::set_maxtapehead(unsigned long maxtapehead)
{
   max_tape_head = maxtapehead;
}
unsigned long turing_machine::get_maxtapehead()const
{
    return max_tape_head;
}
void turing_machine::intialize(int newnum)
{
    if((newnum < 1) || (newnum > (int)inputstrings.size()))
    {
        cout << "invalid input" << endl;
    }
    else
    {
        original_input_string = worked_input_string[newnum-1];
        used = true;
        operating = true;
        accepted = false;
        rejected = false;
        number_of_transitions = 0;
        current_state = initial_state;
        tape.initalize(inputstrings[newnum-1]);        
    }
}
unsigned long turing_machine::get_maxtransitions()
{
    return max_number_transitions;
}
void turing_machine::perform_transitions(int maximum_number_of_transitions)
{
    if(final_states.Is_element(current_state) == true)
    {
        accepted = true;
        operating = false;
        used = true;
        rejected = false;
        cout << "input " << original_input_string << "accepted in " 
        << number_of_transitions << " transitions" <<endl;
        return;
    }
    for(int index = 0; index < maximum_number_of_transitions; index++)
    {
        string dest_state;
        char write_char;
        direction move_direction;
        if(transition_functions.is_defined_transition(current_state,
            tape.current_character(), dest_state, write_char, move_direction) == true)
        {
             tape.update(write_char, move_direction);
             number_of_transitions++;
             current_state = dest_state;
             if(final_states.Is_element(current_state) == true)
             {
                accepted = true;
                operating = false;
                used = true;
                rejected = false;
                cout << "input " << original_input_string << "accepted in " 
                << number_of_transitions << " transitions" <<endl;
                return;
             }             
        }
        else
        {
            rejected = true;
            accepted = false;
            used = true;
            operating = false;
            cout << "input " << original_input_string << "rejected in " 
                << number_of_transitions << " transitions" <<endl;
            return;

        }      
    }
}
void turing_machine::terminate_operation()
{
    accepted = false;
    operating = false;
    used = true;
    rejected = false;
    cout << "operation terminated, it was neither rejected or accepted" << endl;
}
void turing_machine::view_instantaneous_description(int maximum_number_of_cells)const
{
    cout << tape.left(maximum_number_of_cells) << "[" << current_state << "]"
        << tape.right(maximum_number_of_cells) << endl;
}
string turing_machine::input_string()const
{
    return original_input_string;
}
int turing_machine::total_number_of_transitions()const
{
    return max_number_transitions;
}
bool turing_machine::is_valid_definition()const
{
    return valid;
}
bool turing_machine::is_valid_input_string(string value)const
{  
    bool choice = true; 
    if((value.size() == 1)&&(value[0] == '\\')) 
    {
        return choice;
    }
    for(int index = 0; index < (int)value.size(); index++)
    {
        if(!input_alphabet.Is_element(value[index]))
        {
             choice = false;             
        }
    }
    return choice;
   
}
bool turing_machine::is_used()const
{
    return used;
}
bool turing_machine::is_operating()const
{
    return operating;
}
bool turing_machine::is_accepted_input_string()const
{
    return accepted;
}
bool turing_machine::is_rejected_input_string()const
{
    return rejected;
}
bool turing_machine::is_help_enabled()const
{
    return enable_help;
}