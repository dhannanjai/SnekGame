#include "Goal.h"

Goal::Goal(std::mt19937 & rng, const Board & brd, const Snake & snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937 & rng, const Board & brd, const Snake & snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 1);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 1);

	Location newLocation;
	do
	{
		newLocation.x = xDist(rng);
		newLocation.y = yDist(rng);
	} while (snek.IsInTile(newLocation));

	loc = newLocation;
}

void Goal::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Goal::GetLocation() const
{
	return loc;
}
