#pragma once

#include"Snake.h"
#include<random>

class Goal
{
private:
	static constexpr Color c = Colors::Red;
	Location loc;
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Respawn(std::mt19937& rng, const Board& brd , const Snake& snek);
	void Draw(Board& brd)const;
	const Location& GetLocation()const;
};