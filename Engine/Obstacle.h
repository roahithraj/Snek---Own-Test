#pragma once
#include "Location.h"
#include "Board.h"
#include <random>

class Obstacle
{

private:
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	Color c = Colors::Blue;
	static constexpr int nObs = 10;

// ---------------------------------------------------------------------------------- -
	class Obs {
	private:
		Location ObsLocation;
	public:
		void initObs(const Location&);
		Location getLoc();
};
//------------------------------------------------------------------------------------
public:
	void initObstacle();
	bool CheckCollision(Location&, Location&);
	Obstacle(Board& brd);
	Obs obstacles[nObs];

};

