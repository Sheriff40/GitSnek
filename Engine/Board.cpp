#include "Board.h"


Board::Board(Graphics & gfx)
	:
	abc(gfx)
{
}

int Board::GetHeight() const
{
	return height;
}

int Board::GetWidth() const
{
	return width;
}

bool Board::IsInBoard(Location & loc_in) const
{
	return (loc_in.x == 1 || loc_in.x == width || loc_in.y == 1 || loc_in.y == height);
}
