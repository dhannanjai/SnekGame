#include "Board.h"

Board::Board(Graphics & gfx)
	:
	gfx(gfx)
{
	
	assert(boundaryOffset.x > 0);
	assert(boundaryOffset.x + gridWidth * gridDimension < Graphics::ScreenWidth);
	assert(boundaryOffset.y > 0);
	assert(boundaryOffset.y + gridHeight * gridDimension < Graphics::ScreenHeight);
}

bool Board::IsInsideBoard(const Location & loc)
{
	bool ans;
	bool p = loc.x*gridDimension + boundaryOffset.x < (boundaryOffset.x + gridWidth*gridDimension);
	bool q = loc.x*gridDimension + boundaryOffset.x >= boundaryOffset.x;
	bool r = loc.y*gridDimension + boundaryOffset.y >= boundaryOffset.y;
	bool s = loc.y*gridDimension + boundaryOffset.y < (boundaryOffset.y + gridHeight*gridDimension);
	ans = p && q && r && s;
	return ans;
}

void Board::DrawCell(const Location & loc, const Color c)
{
	assert(loc.x >= 0);
	assert(loc.x <= gridWidth*gridDimension);
	assert(loc.y >= 0);
	assert(loc.y <= gridHeight*gridDimension);

	gfx.DrawRectDim(boundaryOffset.x + loc.x*gridDimension,
		boundaryOffset.y + loc.y*gridDimension, gridDimension, gridDimension, c);
}

int Board::GetGridHeight() const
{
	return gridHeight;
}

int Board::GetGridWidth() const
{
	return gridWidth;
}

void Board::DrawBoundary()
{
	for (int i = boundaryOffset.x; i < boundaryOffset.x + gridDimension*gridWidth; i++)
		gfx.PutPixel(i, boundaryOffset.y, boundaryColor);

	for (int i = boundaryOffset.x; i < boundaryOffset.x + gridDimension*gridWidth; i++)
		gfx.PutPixel(i, boundaryOffset.y + gridDimension*gridHeight, boundaryColor);

	for (int i = boundaryOffset.y; i < boundaryOffset.y + gridDimension*gridHeight; i++)
		gfx.PutPixel(boundaryOffset.x, i, boundaryColor);

	for (int i = boundaryOffset.y; i < boundaryOffset.y + gridDimension*gridHeight; i++)
		gfx.PutPixel(boundaryOffset.x + gridDimension * gridWidth, i, boundaryColor);
}
