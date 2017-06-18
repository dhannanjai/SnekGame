#pragma once
#include"Location.h"
#include"Graphics.h"
#include<assert.h>
#include<random>

class Board
{
	Graphics& gfx;
	static constexpr Color boundaryColor = Colors::White;

public:
	Board(Graphics& gfx);
	bool IsInsideBoard(const Location& loc);
	void DrawCell(const Location& loc, const Color c);
	int GetGridHeight()const;
	int GetGridWidth()const;
	void DrawBoundary();
	static constexpr int gridDimension = 20;
	static constexpr int gridHeight = 25;
	static constexpr int gridWidth = 36;
	static constexpr Location boundaryOffset = { (Graphics::ScreenWidth - gridWidth * gridDimension) / 2,
		(Graphics::ScreenHeight - gridHeight * gridDimension) / 2 };
};