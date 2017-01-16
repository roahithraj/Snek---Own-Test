#pragma once
#include "Graphics.h"
#include "Location.h"
class Board
{
private:
	Graphics& gfx;
	static constexpr int cellSize = 25;
	static constexpr int width = 800;
	static constexpr int height = 600;
	Location loc;
	Color c;
public:
	void Draw(const Location loc, Color c);
	Board(Graphics &gfx);
	int getWidth() const;
	int getHeight() const;
	int getCellSize() const;
};

