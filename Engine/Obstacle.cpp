#include "Obstacle.h"

bool Obstacle::CheckCollision(Location& head, Location& Obs) {
	return
		head.x == Obs.x &&
		head.y == Obs.y;
}

Location Obstacle::GetLocation() {
	return ObsLocation;
}

void Obstacle::initObs(const Location& loc) {
	ObsLocation = loc;
}


void Obstacle::DrawObs(Board& brd) {
	brd.Draw(ObsLocation, c);
}
