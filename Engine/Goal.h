#pragma once
#include "Location.h"
#include "Graphics.h"
#include "Board.h"
#include "Snake.h"
#include <random>

class Goal {
private:
	Location Loc;
	Color c = Colors::Red;
public:
	Goal(std::mt19937& rng, Snake& snake, Board& brd);
	void respawn(std::mt19937& rng, Snake& snake, Board& brd);
	void DrawGoal(Board& brd)
	{
		brd.DrawCell(Loc, c);
	};
	bool IsEating(const Location& in_loc);
};