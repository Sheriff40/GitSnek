#pragma once
#include "Board.h"
class Snake
{
private:
	class Segment
	{
	private:
		Location Loc;
		Color c;
	public:
		void InitHead(const Location& int_loc);
		void InitBody();
		void Follow(const Segment& next_segment);
		void Move(const Location& delta_loc);
		void Draw(Board& brd) const;
	};
private:
	static constexpr Color HeadColor = Colors::Yellow;
	static constexpr Color BodyColor = Colors::Blue;
	static constexpr int MaxSegments = 100;
	Segment segment[MaxSegments];
	int nsegment = 1;
public:
	Snake(const Location& int_loc);
	void Grow();
	void MoveBy(const Location& delta_loc);
	void Draw(Board& brd) const;

};