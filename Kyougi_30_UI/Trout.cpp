#include"Headers_include.hpp"
#include"Constant_expressions.hpp"



int Trout::get_index_raw() const
{
	return index_raw;
}

int Trout::get_index_col() const
{
	return index_col;
}

void Trout::set_point(int IND_R, int IND_C)
{
	index_raw = IND_R;

	index_col = IND_C;
}

void Trout::set_number(int NUMBER)
{
	number = NUMBER;
}

void Trout::set_state(int STATE)
{
	state = STATE;
}

int Trout::get_state() const
{
	return state;
}
