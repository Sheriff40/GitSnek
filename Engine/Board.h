#pragma once
#include "Location.h"
#include "Graphics.h"
#include <assert.h>

class Board {
private:
	static constexpr int width = 25;
	static constexpr int height =25;
	static constexpr int dimension = 20;
	Graphics &abc;
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& Loc, Color c )
	{
		assert(Loc.x >= 0);
		assert(Loc.x < width);
		assert(Loc.y >= 0);
		assert(Loc.y < height);
		abc.DrawRectDim(Loc.x *dimension, Loc.y *dimension, dimension, dimension, c);
	}
	int GetHeight() const;
	int GetWidth() const;

};