#pragma once

#include "Location.h"
#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <random>

class Obstacle
{
private:
	Location Loc;
	static constexpr Color c = Colors::Magenta;
public:
	Obstacle(std::mt19937& rng, const Snake& snake,const Board& brd, const Goal& goal);
	void Random(std::mt19937& rng, const Snake& snake, const Board& brd, const Goal& goal);
	void Draw(Board& brd) const
	{
		brd.DrawCell(Loc, c);
	}
	const Location& GetLocation() const;
};
