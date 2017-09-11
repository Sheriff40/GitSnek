#include "Obstacle.h"

Obstacle::Obstacle(std::mt19937& rng, const Snake& snake, const Board& brd, const Goal& goal)
{
	Random(rng, snake, brd, goal);
}

void Obstacle::Random(std::mt19937& rng, const Snake& snake, const Board& brd, const Goal& goal)
{
	std::uniform_int_distribution<int>xDist(2, brd.GetWidth());
	std::uniform_int_distribution<int>yDist(2, brd.GetHeight());
	Location temp_loc;
	do
	{
		temp_loc.x = xDist(rng);
		temp_loc.y = yDist(rng);
	} while (snake.IsInTile2(temp_loc) && goal.IsInTile4(temp_loc));
	Loc = temp_loc;
}

const Location & Obstacle::GetLocation() const
{
	return Loc;
}
