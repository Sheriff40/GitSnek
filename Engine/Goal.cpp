#include "Goal.h"



Goal::Goal(std::mt19937 & rng, Snake& snake, Board& brd)
{
	respawn(rng, snake,brd);
}

void Goal::respawn(std::mt19937 & rng, Snake& snake, Board& brd)
{
	std::uniform_int_distribution<int>xDist(2, brd.GetWidth() - 1);
	std::uniform_int_distribution<int>yDist(2, brd.GetHeight() -1 );
	Location temp_loc;
	do
	{
		temp_loc.x = xDist(rng);
		temp_loc.y = yDist(rng);
	} while (snake.IsInTile(temp_loc));
	Loc = temp_loc;
}

bool Goal::IsEating(const Location & in_loc)
{
	return Loc == in_loc;
}
