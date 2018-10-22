#include"Headers_include.hpp"
#include"Constant_expressions.hpp"





void Agent::set_point(const int R, const int C)
{
	mR = R;
	
	mC = C;
}


void Agent::set_direction(const int MOVE_R, const int MOVE_C)
{
	move_R = MOVE_R;
	move_C = MOVE_C;
}


int Agent::get_raw_point() const
{
	return mR;
}

int Agent::get_col_point() const
{
	return mC;
}

int Agent::get_raw_dir() const
{
	return move_R;
}

int Agent::get_col_dir() const
{
	return move_C;
}

void Agent::set_doing(const int DO)
{
	Do = DO;
}

int Agent::get_doing() const
{
	return Do;
}

bool Agent::isSameTarget(const Agent& ANOTHER) const
{
	if (ANOTHER.get_raw_point() + ANOTHER.get_raw_dir() == mR + move_R && ANOTHER.get_col_point() + ANOTHER.get_col_dir() == mC + move_C)
		return true;
	else
		return false;
}

bool Agent::isSamePoint(const Agent& ANOTHER) const
{
	if (ANOTHER.get_raw_point() == mR + move_R && ANOTHER.get_col_point() == mC + move_C)
		return true;
	else
		return false;
}

void Agent::set_color(const int COLOR)
{
	color = COLOR;
}

int Agent::get_color() const
{
	return color;
}

void Agent::move(std::vector<std::vector<Trout> > &stage)
{


	mR += move_R;
	mC += move_C;

	move_R = 0;
	move_C = 0;


	if (mR < 0 || mR > stage.size())
		assert(!"x_Size isn't right");
	if (mC < 0 || mC > stage[0].size())
		assert(!"y_Size isn't right");

}

void Agent::remove(std::vector<std::vector<Trout> > &stage)
{
	if(stage[mR + move_R][mC + move_C].get_state() != color)
		stage[mR + move_R][mC + move_C].set_state(NONE);
	

	if (mR + move_R < 0 || mR + move_R > stage.size())
		assert(!"x_Size isn't right");
	if (mC + move_C < 0 || mC + move_C > stage[0].size())
		assert(!"y_Size isn't right");
}

void Agent::deploy(std::vector<std::vector<Trout> > &stage)
{


	if (color != BLUE && color != YELLOW)
		assert(!"Color isn't right!");

	stage[mR][mC].set_state(color);

}

