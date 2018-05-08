#include"Headers_include.hpp"
#include"Constant_expressions.hpp"



void Trout::set_score(int SCORE)
{
	score = SCORE;
}

int Trout::get_score() const
{
	if (state == NONE)
		return 0;

	if(state != INSIDE_B && state != INSIDE_Y && state != INSIDE_BOTH)
		return score;
	else
		return score
}

void Trout::set_state(int STATE)
{
	state = STATE;
}

int Trout::get_state() const
{
	return state;
}
