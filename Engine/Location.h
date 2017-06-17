#pragma once

struct Location
{
	void Add(const Location& val)
	{
		x += val.x;
		y += val.y;
	}
	int x;
	int y;

	bool operator!=(const Location& loc)const
	{
		return (x != loc.x && y != loc.y);
	}
	bool operator==(const Location& rhs)const
	{
		return (x == rhs.x && y == rhs.y);
	}
};