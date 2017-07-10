#include "Goal.h"
#include "Obstacle.h"


Goal::Goal(Board& brd)
	:
	rng(std::random_device()()),
	xDist(0, brd.getWidth() / brd.getCellSize() - 2),
	yDist(0, brd.getHeight() / brd.getCellSize() - 1)
{
	initGoalLoc({ 1,1 });
}

void Goal::DrawGoal(Board& brd) {
		brd.Draw(GoalLocation, c);
}

bool Goal::CheckCollision(Location& head, Location& goal) {
	return
		head.x == goal.x &&
		head.y == goal.y;
}

Location Goal::GetLocation() {
	return GoalLocation;
}

void Goal::initGoalLoc(const Location& loc) {
	GoalLocation = { xDist(rng),yDist(rng) };
	while (loc == GoalLocation) {
		GoalLocation = { xDist(rng),yDist(rng) };
	}
}

