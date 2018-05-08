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

void Agent::move(int direction, std::vector<std::vector<Trout> > &stage)
{
	switch (direction)
	{
	case UP:
		if(mY > 0)
			--mY;
		break;

	case DOWN:
		if (mY < stage[0].size())
			++mY;
		break;

	case RIGHT:
		if (mX < stage.size())
			++mX;
		break;

	case LEFT:
		if (mX > 0)
			--mX;
		break;

	case UP_RIGHT:
		if (mY > 0)
			--mY;
		if (mX < stage.size())
			++mX;
		break;

	case DOWN_RIGHT:
		if (mY < stage[0].size())
			++mY;
		if (mX < stage.size())
			++mX;
		break;

	case DOWN_LEFT:
		if (mY < stage[0].size())
			++mY;
		if (mX > 0)
			--mX;
		break;

	case UP_LEFT:
		if (mY > 0)
			--mY;
		if (mX > 0)
			--mX;

		break;

	default:
		assert(!"Direction isn't right!");
		break;


	}
}

void Agent::remove(int direction, std::vector<std::vector<Trout> > &stage)
{
	int removed_mY = mY;

	int removed_mX = mX;

	switch (direction)
	{
	case UP:
		if (mY > 0)
			--removed_mY;
		break;

	case DOWN:
		if (mY < stage[0].size())
			++removed_mY;
		break;

	case RIGHT:
		if (mX < stage.size())
			++removed_mX;
		break;

	case LEFT:
		if (mX > 0)
			--removed_mX;
		break;

	case UP_RIGHT:
		if (mY > 0)
			--removed_mY;
		if (mX < stage.size())
			++removed_mX;
		break;

	case DOWN_RIGHT:
		if (mY < stage[0].size())
			++removed_mY;
		if (mX < stage.size())
			++removed_mX;
		break;

	case DOWN_LEFT:
		if (mY < stage[0].size())
			++removed_mY;
		if (mX > 0)
			--removed_mX;
		break;

	case UP_LEFT:
		if (mY > 0)
			--removed_mY;
		if (mX > 0)
			--removed_mX;
		break;

	default:
		assert(!"Direction isn't right!");
		break;
	}

	stage[removed_mY][removed_mX].set_state(NONE);

}

void Agent::deploy(int direction, int color, std::vector<std::vector<Trout> > &stage)
{
	int placed_mY = mY;

	int placed_mX = mX;

	switch (direction)
	{
	case UP:
		if (mY > 0)
			--placed_mY;
		break;

	case DOWN:
		if (mY < stage[0].size())
			++placed_mY;
		break;

	case RIGHT:
		if (mX < stage.size())
			++placed_mX;
		break;

	case LEFT:
		if (mX > 0)
			--placed_mX;
		break;

	case UP_RIGHT:
		if (mY > 0)
			--placed_mY;
		if (mX < stage.size())
			++placed_mX;
		break;

	case DOWN_RIGHT:
		if (mY < stage[0].size())
			++placed_mY;
		if (mX < stage.size())
			++placed_mX;
		break;

	case DOWN_LEFT:
		if (mY < stage[0].size())
			++placed_mY;
		if (mX > 0)
			--placed_mX;
		break;

	case UP_LEFT:
		if (mY > 0)
			--placed_mY;
		if (mX > 0)
			--placed_mX;
		break;

	default:
		assert(!"Direction isn't right!");
		break;
	}

	if (color != BLUE && color != YELLOW)
		assert(!"Color isn't right!");

	stage[placed_mY][placed_mX].set_state(color);

}

