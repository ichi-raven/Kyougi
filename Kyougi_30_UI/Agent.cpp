#include"Headers_include.hpp"
#include"Constant_expressions.hpp"





void Agent::set_point(const int X, const int Y)
{
	mX = X;
	
	mY = Y;
}

int Agent::get_xpoint() const
{
	return mX;
}

int Agent::get_ypoint() const
{
	return mY;
}

void Agent::set_color(const int COLOR)
{
	color = COLOR;
}

int Agent::get_color() const
{
	return color;
}

void Agent::move(int X, int Y, std::vector<std::vector<Trout> > &stage)
{
	if (X < 0 || X > stage[0].size())
		assert(!"x_Size isn't right");
	if (Y < 0 || Y > stage.size())
		assert(!"y_Size isn't right");


	mX = X;
	mY = Y;
}

void Agent::remove(int X, int Y, std::vector<std::vector<Trout> > &stage)
{
	if (X < 0 || X > stage[0].size())
		assert(!"x_Size isn't right");
	if (Y < 0 || Y > stage.size())
		assert(!"y_Size isn't right");


	stage[Y][X].set_state(NONE);

}

void Agent::deploy(int X, int Y, int color, std::vector<std::vector<Trout> > &stage)
{
	if (X < 0 || X > stage[0].size())
		assert(!"x_Size isn't right");
	if (Y < 0 || Y > stage.size())
		assert(!"y_Size isn't right");


	if (color != BLUE && color != YELLOW)
		assert(!"Color isn't right!");

	stage[Y][X].set_state(color);

}

