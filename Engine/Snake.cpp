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
		++nsegment;
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
	for (int i = 0; i < nsegment; i++)
	{
		segment[i].Draw(brd);
	}
}

Location & Snake::GetNextLocation(const Location & delta_loc)
{
	Location l(segment[0].Getlocation());
	l.Add(delta_loc);
	return l;
}

bool Snake::IsInTile(const Location& target)
{
	for (int i = 0; i < nsegment; i++)
	{
		if (segment[i].Getlocation() == target)
		{
			return true;
		}
	}
}


void Snake::Segment::InitHead(const Location & int_loc)
{
	Loc = int_loc;
	c = Snake::HeadColor;
}

void Snake::Segment::InitBody()
{
	c = Snake::BodyColor;
}

void Snake::Segment::Follow(const Segment& next_segment)
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

Location & Snake::Segment::Getlocation()
{
	return Loc;
}