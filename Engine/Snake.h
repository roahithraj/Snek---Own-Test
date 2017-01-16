#pragma once
#include "Board.h"
class Snake
{
private:
	static constexpr Color headColor = Colors::Red;
	static constexpr Color bodyColor = Colors::Gray;
	static constexpr int MaxSeg = 100;
	int nSeg = 10;
//-----------------------------------------------------------------------------------
	class Segment {
	private:
		Location loc;
		Color c;
	public:
		void initHead(const Location&);
		void initBody(const Location&, int);
		void Moveby(const Location&, Board&);
		void Follow(const Segment&);
		void DrawSeg(Board&);
		Location getLoc();
	};
//------------------------------------------------------------------------------------
private:
	Segment Seg[MaxSeg];
	bool loop = false;
	int colorInc = 50;
	bool flag = true;

public:
	Location getHeadLocation();
	void Draw(Board&);
	void Moveby(const Location&, Board&);
	void Grow();
	Snake(const Location& loc);
	bool getLoopState() const;
	void DrawHead(Board&);
};

