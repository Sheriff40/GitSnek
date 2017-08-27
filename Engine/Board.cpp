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
