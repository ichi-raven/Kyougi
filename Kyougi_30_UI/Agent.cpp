#include"Headers_include.hpp"
#include"Constant_expressions.hpp"





void Agent::set_point(const int R, const int C)
{
	mR = R;
	
	mC = C;
}

int Agent::get_raw_point() const
{
	return mR;
}

int Agent::get_col_point() const
{
	return mC;
}

bool Agent::isSamePoint(const Agent& ANOTHER, const int MOVE_R, const int MOVE_C) const
{
	if (ANOTHER.get_raw_point() == mR + MOVE_R && ANOTHER.get_col_point() == mC + MOVE_C)
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

void Agent::move(const int R, const int C, std::vector<std::vector<Trout> > &stage)
{
	if (R < 0 || R > stage.size())
		assert(!"x_Size isn't right");
	if (C < 0 || C > stage[0].size())
		assert(!"y_Size isn't right");


	mR = R;
	mC = C;
}

void Agent::remove(const int R, const int C, std::vector<std::vector<Trout> > &stage)
{
	if (R < 0 || R > stage[0].size())
		assert(!"x_Size isn't right");
	if (C < 0 || C > stage.size())
		assert(!"y_Size isn't right");


	stage[R][C].set_state(NONE);

}

void Agent::deploy(const int R, const int C, int color, std::vector<std::vector<Trout> > &stage)
{
	if (R < 0 || R > stage.size())
		assert(!"x_Size isn't right");
	if (C < 0 || C > stage[0].size())
		assert(!"y_Size isn't right");


	if (color != BLUE && color != YELLOW)
		assert(!"Color isn't right!");

	stage[R][C].set_state(color);

}

