#pragma once
#include"Snake.h"

class Obstacles
{
private:
	class Rock
	{
		Location loc;
		static constexpr Color c = Colors::Gray;
	public:
		void Create(std::mt19937& rng, const Board& brd, const Snake& snek);
		void Draw(Board& brd)const;
		const Location& GetLocation()const;
	};

private:
	Location loc;
	static constexpr int maxNumberOfRocks = 100;
	Rock rocks[maxNumberOfRocks];
	int nRocks = 0;
public:
	Obstacles(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Increase(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Draw(Board& brd)const;
	bool Check(const Snake& snek)const;
};