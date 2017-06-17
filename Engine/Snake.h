#pragma once
#include"Board.h"

class Snake
{
private:
	class Segment {
		Location loc;
		Color c;
	public:
		void InitHead(const Location& loc);
		void initBody();
		void Follow(const Segment& next);
		void MoveBy(const Location& delta_loc);
		void Draw(Board& brd)const;
		const Location GetLocation()const;
	};

public:
	Snake(const Location& loc);
	void MoveBy(const Location& delta_loc);
	Location GetNextHeadLocation(const Location& delta_loc)const;
	void Grow();
	void Draw(Board& brd)const;
	bool IsInTileExceptEnd(const Location& loc)const;
	bool IsInTile(const Location& loc)const;
private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor = Colors::Green;
	static constexpr int nSegmentsMax = 100;
	Segment segments[nSegmentsMax];
	int nSegments = 1;
};