//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//tape.h

#ifndef Tape_h
#define Tape_h

#include "direction.h"
#include <string>
#include <fstream>
using namespace std;

class Tape
{
private:
	string cells;
	int current_cell;
	char blank;
public:
	Tape();
	void load(ifstream& definition, bool& valid);
	void view() const;
	void initalize(string input_string);
	void update(char write_character, direction move_direction);
	string left(int max_number_of_cells) const;
	string right(int max_number_of_cells) const;
	char current_character() const;
	char blank_character() const;
	bool is_first_cell() const;	
};

#endif