#pragma once
#include"Location.h"
#include"Graphics.h"
#include<assert.h>

class Board
{
	static constexpr int gridDimension = 20;
	static constexpr int gridHeight = 30;
	static constexpr int gridWidth = 30;
	Graphics& gfx;

public:
	Board(Graphics& gfx);
	bool IsInsideBoard(const Location& loc);
	void DrawCell(const Location& loc, const Color c);
	int GetGridHeight()const;
	int GetGridWidth()const;
};