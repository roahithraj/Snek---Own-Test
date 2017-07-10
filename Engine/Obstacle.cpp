#include "Obstacle.h"


Obstacle::Obstacle(Board& brd)
	:
	rng(std::random_device()()),
	xDist(0, brd.getWidth() / brd.getCellSize() - 2),
	yDist(0, brd.getHeight() / brd.getCellSize() - 1)
{
	
}

bool Obstacle::CheckCollision(Location& head, Location& Obs) {
	return
		head.x == Obs.x &&
		head.y == Obs.y;
}


void Obstacle::initObstacle() {
	for (int i = 0; i < nObs; i++) {
		Location newloc = { xDist(rng),yDist(rng) };
		obstacles[i].initObs(newloc);
	}
}

void Obstacle::Obs::initObs(const Location& loc) {

}