#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location & int_loc)
{
	segment[0].InitHead(int_loc);
}

void Snake::Grow()
{
	if (nsegment < MaxSegments)
	{
		segment[nsegment].InitBody();
		nsegment++;
	}
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nsegment - 1; i > 0; i--)
	{
		segment[i].Follow(segment[i - 1]);
	}
	segment[0].Move(delta_loc);
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < MaxSegments; i++)
	{
		segment[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location & int_loc)
{
	Loc = int_loc;
	Color c = HeadColor;
}

void Snake::Segment::InitBody()
{
	Color c = BodyColor;
}

void Snake::Segment::Follow(const Segment & next_segment)
{
	Loc = next_segment.Loc;
}

void Snake::Segment::Move(const Location& delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	Loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd) const
{
	brd.DrawCell(Loc, c);
}

