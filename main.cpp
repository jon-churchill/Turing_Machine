//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++

#include "turing_machine.h"
#include "Tape.h"
#include "upperCase.h"
#include "Input_alphabet.h"
#include "tape_alphabet.h"
#include "transition_function.h"
#include "State.h"
#include "final_state.h"
#include "stdlib.h"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <climits>
#include <cerrno>
using namespace std;

int main(int argc, char* argv[])
{
    int returnsuccess = 0;
    bool writetofile = false;    
    if(argc == 2)
    {
        turing_machine tm(argv[1]);
        int infinitewhile = 1;
        string getnum;
        string transnumber;        
        string maxtapehead;
        string linenum;       
        string commandstring = "";
        char commandchar;
        string newinputstring = "";
        upperCase uppercaseobj;
        while(infinitewhile == 1)
        {
          cout << "Command: ";          
          getline(cin, commandstring);                       
            if(commandstring.length() == 1)
            {
                commandchar = commandstring[0];
                switch (uppercaseobj.uppercase(commandchar))
                {                    
                    case 'D':
                        if(tm.enable_help == false)
                        {
                            cout << "this will remove the inputed line number" <<endl;
                        }
                            cout << "Delete line number: ";
                            getline(cin, linenum);
                            if(linenum.length() == 0)
                            {

                            }
                            else
                            {
                                int delline = atoi(linenum.c_str());
                                unsigned long Dulong = strtoul(linenum.c_str(), NULL, 0);
                                if((delline < 0) || (Dulong < 1) ||(errno == ERANGE) || (Dulong == ULONG_MAX))
                                {
                                    errno = 0;
                                    cout << "input string has not been updated"<<endl;
                                }
                                if(tm.deletestring(delline) == true)
                                {
                                    writetofile = true;
                                }                                           
                            }                            
                        
                       
                        break;
                    case 'X':
                        if(tm.enable_help == true)
                        {
                            cout << "Exiting the application....have a nice day" << endl;
                        }
                        if(writetofile == true)
                        {
                            cout << "saving file and exiting" << endl; 
                            tm.write(argv[1]);                    
                        } 
                        return returnsuccess;                      
                        break;
                    case 'H':
                        if(tm.is_help_enabled() == false)
                        {
                            tm.enable_help = true;
                            cout << "D- Delete – delete input string from list" <<endl;
                            cout << "X- Exit – exit application" <<endl;
                            cout << "H- Help – help user with prompts or not" <<endl;
                            cout << "I- Insert – insert input string into list" <<endl;
                            cout << "L- List – list input strings" <<endl;
                            cout << "Q- Quit – quit operation of TM on input string" <<endl;
                            cout << "R- Run – run TM on input string" <<endl;
                            cout << "E- Set – set maximum number of transitions to perform" <<endl;
                            cout << "W- Show – show status of application" <<endl;
                            cout << "T- Truncate – truncate instantaneous descriptions" <<endl;
                            cout << "V- View – view TM" <<endl;
                        }
                        else
                        {
                            tm.enable_help = false;
                            cout << "help has been disabled" << endl;
                        }
                        break;
                    case 'I':
                        if(tm.enable_help == false)
                        {
                            newinputstring="";
                            cout << "Input String: ";                            
                            getline(cin,newinputstring); 
                            if(tm.insert_string(newinputstring) == true)
                            {
                                writetofile = true;
                            }
                        }
                        else
                        {
                            newinputstring="";
                            cout << "This will insert text onto the end of the list" << endl;
                            cout << "Input String: ";                            
                            getline(cin,newinputstring); 
                            if(tm.insert_string(newinputstring) == true)
                            {
                                writetofile = true;
                            }
                        }
                        break;
                    case 'L':
                        if(tm.enable_help == false)
                        {
                            tm.view_inputstrings();
                        }
                        else
                        {
                            cout << "this is the contents of the .str file" << endl;
                            tm.view_inputstrings();
                        }
                        break;
                    case 'Q':
                        if(tm.enable_help == false)
                        {
                            cout << "quiting application and saving to file if changed" << endl;
                            if(writetofile == true)
                            {
                                tm.terminate_operation();
                                cout << "saving file" << endl; 
                                tm.write(argv[1]);                    
                            } 
                            else
                            {
                                tm.terminate_operation();
                            }
                        }
                        else
                        {
                            
                        }
                        break;
                    case 'R':
                        if(tm.enable_help == true)
                        {
                        }

                        if(tm.is_operating() == true)
                        {
                            tm.perform_transitions(tm.get_maxtransitions());
                            tm.view_instantaneous_description(tm.get_maxtapehead());
                        }
                        else
                        {
                            cout << "input string" << endl;
                            getline(cin, getnum); 
                            int newnum = atoi(getnum.c_str());
                            unsigned long Rulong = strtoul(getnum.c_str(), NULL, 0);
                            if((newnum < 0) || (Rulong < 1) ||(errno == ERANGE) || (Rulong == ULONG_MAX))
                            {
                                errno = 0;
                                cout << "input string has not been updated"<<endl;
                            }
                            tm.intialize(newnum);
                            tm.view_instantaneous_description(tm.get_maxtapehead());
                            tm.perform_transitions(tm.get_maxtransitions());
                            tm.view_instantaneous_description(tm.get_maxtapehead());
                        }
                        
                        
                        break;
                    case 'E':
                        if(tm.enable_help == true)
                        {
                            cout << "this sets the number of transitions to perform per run" << endl;
                        } 
                        getline(cin,transnumber);                           
                        if(transnumber.length() == 0)
                        {                                                         
                            
                        }
                        else
                        {                            
                            int newtransnum = atoi(transnumber.c_str());
                            unsigned long Eulong = strtoul(transnumber.c_str(), NULL, 0);
                            if((newtransnum < 0) || (Eulong < 1) ||(errno == ERANGE) || (Eulong == ULONG_MAX))
                            {
                                errno = 0;
                                cout << "The maximum number of transitions has not been updated"<<endl;
                            }
                            else
                            {
                                tm.set_transitions(Eulong);                               
                                cout << "The number of transitions has been updated" <<endl;
                            }
                        }
                       
                        break;                   
                    case 'W':
                        if(tm.enable_help == false)
                        {
                            cout << "Course: Cpts322\nSemester: Spring\nYear: 2013\nInstructor: Neil Corrigan" << endl;
                            cout << "Author: Jon Churchill\nVersion of Application: 1.0" << endl;
                            cout << "Configuration Settings:\n\tHelp Message: off" << endl;
                            cout << "\tMaximum Transitions:" << tm.total_number_of_transitions() << endl;
                            cout << "\tMaximum number of cells displayed:" << tm.get_maxtapehead() << endl;
                            cout << "Name of Turing Machine: " << argv[1] << endl;
                        }
                        else
                        {
                            cout << "Course: Cpts322\nSemester: Spring\nYear: 2013\nInstructor: Neil Corrigan" << endl;
                            cout << "Author: Jon Churchill\nVersion of Application: 1.0" << endl;                            
                            cout << "Configuration Settings:\n\tHelp Message: on" << endl;                            
                            cout << "\tMaximum Transitions:" << tm.total_number_of_transitions() << endl;
                            cout << "\tMaximum number of cells displayed:" << tm.get_maxtapehead() << endl;
                            cout << "Name of Turing Machine: " << argv[1] << endl;
                        }
                        break;
                    case 'T':
                        if(tm.enable_help == true)
                        {
                            cout << "this truncates each side of the tapehead to inputed value" << endl;
                        }                            
                        cout <<"Maximum number of cells[" <<tm.get_maxtapehead()<<"]: ";
                        getline(cin, maxtapehead);
                        if(maxtapehead.length() == 0)
                        {                                                         
                            
                        }
                        else
                        {
                            int converted = atoi(maxtapehead.c_str());
                            unsigned long Tulong = strtoul(maxtapehead.c_str(), NULL, 0);
                            if((converted < 0) || (Tulong < 1) ||(errno == ERANGE) || (Tulong == ULONG_MAX))
                            {
                                errno = 0;
                                cout << "The maximum number of cells has not been updated"<<endl;
                            }
                            else
                            {
                                tm.set_maxtapehead(Tulong);                                
                                cout << "The maximum number of cells has been updated"<<endl;
                            }
                        }
                        break;
                    case 'V':
                        if(tm.enable_help == false)
                        {
                            tm.view_definition();
                        }
                        else
                        {
                            
                        }
                        break;
                    default:   
                        if(tm.enable_help == false)
                        {
                            cout << "Invalid command argument, use H for help" <<endl; 
                        }                     
                        else
                        {
                            
                        }                                           
                        break;
                }               
            }
            else if(commandstring.length() == 0)
            {

            }
            else
            {
                cout << "Invalid command argument, use H for help" <<endl;
            }
        }                
        return returnsuccess;
    }    
    else
    {
        cout <<"Incorrect number of command line arguments\n";
        return returnsuccess;
    }

    

}