#include"Headers_include.hpp"
#include"Constant_expressions.hpp"


Agent::Agent(int STATE)
{
	state = STATE;

	if (state != BLUE && state != YELLOW)
		assert(!"color isn't right");
}



void Agent::set_point(int IND_R, int IND_C)
{
	index_raw = IND_R;

	index_col = IND_C;
}

void Agent::move(int direction, std::vector<std::vector<Trout> > &stage)
{
	switch (direction)
	{
	case UP:
		if(index_raw > 0)
			--index_raw;
		break;

	case DOWN:
		if (index_raw < stage.size())
			++index_raw;
		break;

	case RIGHT:
		if (index_col < stage[0].size())
			++index_col;
		break;

	case LEFT:
		if (index_col > 0)
			--index_col;
		break;

	case UP_RIGHT:
		if (index_raw > 0)
			--index_raw;
		if (index_col < stage[0].size())
			++index_col;
		break;

	case DOWN_RIGHT:
		if (index_raw < stage.size())
			++index_raw;
		if (index_col < stage[0].size())
			++index_col;
		break;

	case DOWN_LEFT:
		if (index_raw < stage.size())
			++index_raw;
		if (index_col > 0)
			--index_col;
		break;

	case UP_LEFT:
		if (index_raw > 0)
			--index_raw;
		if (index_col > 0)
			--index_col;

		break;


	}
}

void Agent::remove(int direction, std::vector<std::vector<Trout> > &stage)
{
	int removed_index_raw = index_raw;

	int removed_index_col = index_col;

	switch (direction)
	{
	case UP:
		if (index_raw > 0)
			--removed_index_raw;
		break;

	case DOWN:
		if (index_raw < stage.size())
			++removed_index_raw;
		break;

	case RIGHT:
		if (index_col < stage[0].size())
			++removed_index_col;
		break;

	case LEFT:
		if (index_col > 0)
			--removed_index_col;
		break;

	case UP_RIGHT:
		if (index_raw > 0)
			--removed_index_raw;
		if (index_col < stage[0].size())
			++removed_index_col;
		break;

	case DOWN_RIGHT:
		if (index_raw < stage.size())
			++removed_index_raw;
		if (index_col < stage[0].size())
			++removed_index_col;
		break;

	case DOWN_LEFT:
		if (index_raw < stage.size())
			++removed_index_raw;
		if (index_col > 0)
			--removed_index_col;
		break;

	case UP_LEFT:
		if (index_raw > 0)
			--removed_index_raw;
		if (index_col > 0)
			--removed_index_col;

		break;
	}

	stage[removed_index_raw][removed_index_col].set_state(NONE);

}

