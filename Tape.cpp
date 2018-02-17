//Jon churchill
//Cpt_s 322
//April 29th 2013
//linux ubuntu 12.10
//Acer Aspire 
//C++
//tape.cpp

#include "Tape.h"
#include "direction.h"
#include "upperCase.h"
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

Tape::Tape():
	cells(" "),
	current_cell(0),
	blank(' ')
{

}

void Tape::load(ifstream& definition, bool& valid)
{
	string value;
	if((definition >> value) && (value.length() == 1)
	 && (value[0] != '\\') && (value[0] != '[') && (value[0] != ']')
	 && (value[0] != '<') && (value[0] >= '!') && (value[0] <= '~')
	 && (value[0] != '>'))
	{
		blank = value[0];
	}
	else
	{
		cout << "illegal blank character. \n";
		valid = false;
	}
	upperCase ucobj;
	if ((!(definition >> value)) || (ucobj.uppercase(value) != "FINAL_STATES:"))
	{
		cout << "missing keyword after blank character. \n";
		valid = false;
	}	
}

void Tape::view() const
{
	cout << "B =  " << blank << "\n\n";
}

void Tape::initalize(string input_string)
{
	cells = input_string + blank;
	current_cell = 0;
}

void Tape::update(char write_character, direction move_direction)
{
	upperCase ucobj;
	move_direction = ucobj.uppercase(move_direction);
	if((move_direction == 'L') && (current_cell == 0))
	{
		return;
	}

	if((move_direction == 'R') && (current_cell == ((int)cells.length() - 1)))
	{
		cells += blank;
	}

	cells[current_cell] = write_character;

	if(move_direction == 'L')
	{
		--current_cell;
	}
	else
	{
		++current_cell;
	}
}

string Tape::left(int max_number_of_cells) const
{
	int first_cell = max(0,(current_cell - max_number_of_cells));
	string value = cells.substr(first_cell, (current_cell - first_cell));
	if((int)value.length() < current_cell)
	{
	 	value.insert(0, "<");
	}
	return value;
}

string Tape::right(int max_number_of_cells) const
{
	int end_cell = cells.length() - 1;
	while((end_cell >= current_cell) && (cells[end_cell] == blank))
	{
		--end_cell;
	}
	int last_cell = min(end_cell, (current_cell + max_number_of_cells - 1));
	string value = cells.substr(current_cell, (last_cell - current_cell + 1));
	if((int)value.length() < (end_cell - current_cell + 1))
	{
		value.append(">");
	}
	return value;
}

char Tape::current_character() const
{
	return cells[current_cell];
}
char Tape::blank_character() const
{
	return blank;
}
bool Tape::is_first_cell() const
{
	if(current_cell == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}