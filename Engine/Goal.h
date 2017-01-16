#pragma once
#include "Location.h"
#include "Board.h"
#include <random>
#include "Obstacle.h"


class Goal
{

private:
	Location GoalLocation;
	std::mt19937 rng;
	std::uniform_int_distribution<int> xDist;
	std::uniform_int_distribution<int> yDist;
	Color c = Colors::Gray;
public:
	Goal(Board&);
	void initGoalLoc(const Location&);
	void DrawGoal(Board&);
	bool CheckCollision(Location&, Location&);
	Location GetLocation();
};

