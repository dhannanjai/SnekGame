#include "Snake.h"

Snake::Snake(const Location & loc )
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location & delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--)
		segments[i].Follow(segments[i - 1]);
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	assert(nSegments + 1 < nSegmentsMax);
	segments[nSegments].initBody();
	nSegments++;
}

void Snake::Draw(Board & brd) const
{
	for (int i = 0; i < nSegments; i++)
		segments[i].Draw(brd);
}

bool Snake::IsInTileExceptEnd(const Location & loc) const
{
	for (int i = 0; i < nSegments - 1; i++)
	{
		if (segments[i].GetLocation() == loc)
			return true;
	}
	return false;
}

bool Snake::IsInTile(const Location & loc) const
{
	for (int i = 0; i < nSegments ; i++)
	{
		if (segments[i].GetLocation() == loc)
			return true;
	}
	return false;
}



/*///////////   Snake Segment ///////////////*/

void Snake::Segment::InitHead(const Location & loc)
{
	this->loc = loc;
	c = Snake::headColor;
}

void Snake::Segment::initBody()
{
	std::uniform_int_distribution<unsigned int> shade(0, 255);
	c = Color(0,255,0);
}

const Location Snake::Segment::GetLocation()const
{
	return loc;
}

Location Snake::GetNextHeadLocation(const Location & delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
}

void Snake::Segment::Follow(const Segment & next)
{
	loc = next.loc;
}

void Snake::Segment::MoveBy(const Location & delta_loc)
{
	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
	loc.Add(delta_loc);
}

void Snake::Segment::Draw(Board & brd ) const
{
	brd.DrawCell(loc, c);
}
