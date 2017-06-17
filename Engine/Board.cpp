#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
}

bool Board::IsInsideBoard(const Location & loc)
{
	return loc.x < gridWidth && loc.x >= 0
		&& loc.y >= 0 && loc.y < gridHeight;
}

void Board::DrawCell(const Location & loc, const Color c)
{
	assert(loc.x >= 0);
	assert(loc.x < gridWidth);
	assert(loc.y >= 0);
	assert(loc.y < gridHeight);

	gfx.DrawRectDim(loc.x*gridDimension, loc.y*gridDimension, gridDimension, gridDimension, c);
}

int Board::GetGridHeight() const
{
	return gridHeight;
}

int Board::GetGridWidth() const
{
	return gridWidth;
}
