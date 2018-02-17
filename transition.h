//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//transitions.h

#ifndef transition_h
#define transition_h

#include "direction.h"
#include <string>
using namespace std;

class transition
{
	private:
		string source;
		char read;
		string destination;
		char write;
		direction move;
	public:
		transition(string source_state, 
				   char read_character, 
				   string destination_state, 
				   char write_character, 
				   direction move_direction);
		string source_state() const;
		char read_character() const;
		string destination_state() const;
		char write_character() const;
		direction move_direction() const;
};


#endif