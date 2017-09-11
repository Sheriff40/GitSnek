#include "Goal.h"



Goal::Goal(std::mt19937 & rng, const Snake& snek, const Board& brd)
{
	respawn(rng, snek,brd);
}

void Goal::respawn(std::mt19937 & rng, const Snake& snek, const Board& brd)
{
	std::uniform_int_distribution<int>xDist(2, brd.GetWidth() - 1);
	std::uniform_int_distribution<int>yDist(2, brd.GetHeight() -1 );
	Location loc;
	do
	{
		loc.x = xDist(rng);
		loc.y = yDist(rng);
	} while (snek.IsInTile(loc));
	Loc = loc;
}

bool Goal::IsEating(const Location & in_loc)
{
	return Loc == in_loc;
}

bool Goal::IsInTile4(const Location & temp_loc) const
{
	if (Loc == temp_loc)
	{
		return true;
	}
}