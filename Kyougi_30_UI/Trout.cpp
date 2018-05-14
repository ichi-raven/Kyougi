#include"Headers_include.hpp"
#include"Constant_expressions.hpp"



void Trout::set_score(const int SCORE)
{
	score = SCORE;
}

int Trout::get_score() const
{
		return score;
}

void Trout::set_state(const int STATE)
{
	state = STATE;
}

int Trout::get_state() const
{
	return state;
}
