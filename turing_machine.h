//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//turing_machine.h

#ifndef turing_machine_h
#define turing_machine_h

#include "Tape.h"
#include "Input_alphabet.h"
#include "tape_alphabet.h"
#include "transition_function.h"
#include "State.h"
#include "final_state.h"
#include <string>
#include <vector>

using namespace std;

class turing_machine
{
  private:        
    Tape tape;
    Input_alphabet input_alphabet;
    tape_alphabet tape_alphabets;
    transition_function transition_functions;
    State states;
    final_state final_states;
    string description;     
    vector<string> inputstrings;   
    string initial_state;          
    string current_state;          
    string original_input_string;   
    string worked_input_string;
    int number_of_transitions;      
    int max_number_transitions;
    int max_tape_head;
    bool help;
    bool valid;         
    bool used;         
    bool operating;
    bool accepted;
    bool rejected;

  public:
    bool enable_help; 
    turing_machine(string definition_file_name);//
    void view_definition()const;//
    bool deletestring(int linenum);
    void view_inputstrings()const;
    bool insert_string(string insertstring);
    unsigned long get_maxtransitions();
    void set_transitions(unsigned long maxtrans);
    void set_maxtapehead(unsigned long maxtapehead);
    unsigned long get_maxtapehead()const;
    void view_instantaneous_description(int maximum_number_of_cells)const;//
    void intialize(int newnum);//
    void perform_transitions(int maximum_number_of_transitions);//
    void terminate_operation();//
    string input_string()const;//
    int total_number_of_transitions()const;//
    bool is_valid_definition()const;//
    bool is_valid_input_string(string value)const;//
    bool is_used()const;//
    bool is_operating()const;//
    bool is_accepted_input_string()const;//
    bool is_rejected_input_string()const;  //  
    bool is_help_enabled()const;
    void write(string definition_file_name);
};

#endif