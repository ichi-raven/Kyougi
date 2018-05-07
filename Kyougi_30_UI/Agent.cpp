#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


Agent::Agent(int STATE)
{
	state = STATE;

	if (state != BLUE && state != YELLOW)
		assert(!"color isn't right");
}



void Agent::set_point(int IND_X, int IND_Y)
{
	index_x = IND_X;

	index_y = IND_Y;
}

void Agent::move(int direction, std::vector<std::vector<Trout> > &stage)
{
	switch (direction)
	{
	case UP:
		if(index_x > 0)
			--index_x;
		break;

	case DOWN:
		if (index_x < stage[0].size())
			++index_x;
		break;

	case RIGHT:
		if (index_y < stage.size())
			++index_y;
		break;

	case LEFT:
		if (index_y > 0)
			--index_y;
		break;

	case UP_RIGHT:
		if (index_x > 0)
			--index_x;
		if (index_y < stage.size())
			++index_y;
		break;

	case DOWN_RIGHT:
		if (index_x < stage[0].size())
			++index_x;
		if (index_y < stage.size())
			++index_y;
		break;

	case DOWN_LEFT:
		if (index_x < stage[0].size())
			++index_x;
		if (index_y > 0)
			--index_y;
		break;

	case UP_LEFT:
		if (index_x > 0)
			--index_x;
		if (index_y > 0)
			--index_y;

		break;

	default:
		assert(!"Direction isn't right!");
		break;


	}
}

void Agent::remove(int direction, std::vector<std::vector<Trout> > &stage)
{
	int removed_index_x = index_x;

	int removed_index_y = index_y;

	switch (direction)
	{
	case UP:
		if (index_x > 0)
			--removed_index_x;
		break;

	case DOWN:
		if (index_x < stage[0].size())
			++removed_index_x;
		break;

	case RIGHT:
		if (index_y < stage.size())
			++removed_index_y;
		break;

	case LEFT:
		if (index_y > 0)
			--removed_index_y;
		break;

	case UP_RIGHT:
		if (index_x > 0)
			--removed_index_x;
		if (index_y < stage.size())
			++removed_index_y;
		break;

	case DOWN_RIGHT:
		if (index_x < stage[0].size())
			++removed_index_x;
		if (index_y < stage.size())
			++removed_index_y;
		break;

	case DOWN_LEFT:
		if (index_x < stage[0].size())
			++removed_index_x;
		if (index_y > 0)
			--removed_index_y;
		break;

	case UP_LEFT:
		if (index_x > 0)
			--removed_index_x;
		if (index_y > 0)
			--removed_index_y;
		break;

	default:
		assert(!"Direction isn't right!");
		break;
	}

	stage[removed_index_x][removed_index_y].set_state(NONE);

}

void Agent::deploy(int direction, int color, std::vector<std::vector<Trout> > &stage)
{
	int placed_index_x = index_x;

	int placed_index_y = index_y;

	switch (direction)
	{
	case UP:
		if (index_x > 0)
			--placed_index_x;
		break;

	case DOWN:
		if (index_x < stage[0].size())
			++placed_index_x;
		break;

	case RIGHT:
		if (index_y < stage.size())
			++placed_index_y;
		break;

	case LEFT:
		if (index_y > 0)
			--placed_index_y;
		break;

	case UP_RIGHT:
		if (index_x > 0)
			--placed_index_x;
		if (index_y < stage.size())
			++placed_index_y;
		break;

	case DOWN_RIGHT:
		if (index_x < stage[0].size())
			++placed_index_x;
		if (index_y < stage.size())
			++placed_index_y;
		break;

	case DOWN_LEFT:
		if (index_x < stage[0].size())
			++placed_index_x;
		if (index_y > 0)
			--placed_index_y;
		break;

	case UP_LEFT:
		if (index_x > 0)
			--placed_index_x;
		if (index_y > 0)
			--placed_index_y;
		break;

	default:
		assert(!"Direction isn't right!");
		break;
	}

	if (color != BLUE && color != YELLOW)
		assert(!"Color isn't right!");

	stage[placed_index_x][placed_index_y].set_state(color);

}

