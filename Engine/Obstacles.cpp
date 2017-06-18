#include "Obstacles.h"

Obstacles::Obstacles(std::mt19937 & rng, const Board & brd, const Snake & snek)
{
	Increase(rng, brd, snek);
}

void Obstacles::Increase(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	assert(nRocks + 1 < maxNumberOfRocks);
	rocks[nRocks].Create(rng, brd, snek);
	nRocks++;
}



void Obstacles::Draw(Board & brd) const
{
	for (int i = 0; i < nRocks; i++)
		rocks[i].Draw(brd);
}

bool Obstacles::Check(const Snake & snek) const
{
	bool answer = false;
	for (int i = 0; i < nRocks; i++)
	{
		answer = snek.IsInTile(rocks[i].GetLocation());
		if (answer == true)
			return true;
	}
	return false;
}

/*///////// /////              Rocks                  ////////////////*/
void Obstacles::Rock::Create(std::mt19937 & rng, const Board & brd, const Snake & snek)
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

void Obstacles::Rock::Draw(Board & brd) const
{
	brd.DrawCell(loc, c);
}

const Location & Obstacles::Rock::GetLocation() const
{
	// TODO: insert return statement here
	return loc;
}
