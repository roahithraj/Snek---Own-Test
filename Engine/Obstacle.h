#pragma once
#include "Location.h"
#include "Board.h"
#include <random>

class Obstacle
{

private:
	Location ObsLocation;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	Color c = Colors::Blue;
public:
	void initObs(const Location&);
	void DrawObs(Board&);
	bool CheckCollision(Location&, Location&);
	Location GetLocation();
};

