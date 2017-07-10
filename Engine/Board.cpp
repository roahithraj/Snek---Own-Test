#include "Board.h"
#include "Snake.h"
#include "Goal.h"
#include <assert.h>



Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
}

int Board::getWidth() const {
	return width;
}

int Board::getHeight() const {
	return height;
}

int Board::getCellSize() const {
	return cellSize;
}


void Board::Draw(const Location loc, Color c) {

	assert(loc.x >= 0);
	assert(loc.x < width);
	assert(loc.y >= 0);
	assert(loc.y < height);
	gfx.DrawRectDim(loc.x*cellSize, loc.y*cellSize, cellSize, cellSize, c);
	
}
