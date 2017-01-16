#include "Snake.h"
#include <assert.h>

Snake::Snake(const Location& loc) {
		Seg[0].initHead(loc);
		for (int i = 1; i < nSeg; i++) {
			if (flag) {
				colorInc -= 50;
				if (colorInc <= 0) {
					flag = false;
				}
			}
			if(!flag) {
				colorInc += 50;
				if (colorInc >= 250) {
						flag = true;
					}
				}
				Seg[i].initBody(loc, colorInc);
			}
		}

void Snake::Moveby(const Location& delta_loc, Board& brd) {
	Location temp;
	for (int i = nSeg; i > 0; i--) {
		temp = { Seg[0].getLoc().x + delta_loc.x, Seg[0].getLoc().y + delta_loc.y };
		if ((temp.x == Seg[i - 2].getLoc().x) && (temp.y == Seg[i - 2].getLoc().y)) {
			loop = true;
		}
		Seg[i].Follow(Seg[i - 1]);
	}
	Seg[0].Moveby(delta_loc, brd);
}


void Snake::Grow() {
	Location temploc = Seg[nSeg - 1].getLoc();
	nSeg++;
	if (flag) {
		colorInc -= 50;
		if (colorInc <= 0) {
			flag = false;
		}
	}
	if (!flag) {
		colorInc += 50;
		if (colorInc >= 250) {
			flag = true;
		}
	}
	Seg[nSeg - 1].initBody(temploc, colorInc);
	Seg[nSeg - 1].Follow(Seg[nSeg - 1]);
}

void Snake::Draw(Board& brd) {
	for (int i = 0; i < nSeg; i++) {
		Seg[i].DrawSeg(brd);
	}
}

Location Snake::getHeadLocation() {
	return Seg[0].getLoc();
}

bool Snake::getLoopState() const {
	return loop;
}

void Snake::DrawHead(Board& brd) {
	Seg[0].DrawSeg(brd);
}



//----------------------------------------------------------------------------------------
void Snake::Segment::initHead(const Location& in_loc) {
	loc = in_loc;
	c = Snake::headColor;	
}

void Snake::Segment::initBody(const Location& in_loc, int in_c) {

	c = { 0,static_cast<unsigned char>(in_c),0 };
	loc = in_loc;
}

void Snake::Segment::Moveby(const Location& delta_loc, Board& brd) {

	assert(abs(delta_loc.x) + abs(delta_loc.y) == 1);
		if ((loc.y < 1) && delta_loc.y==-1){
			initHead({ loc.x, brd.getHeight() / brd.getCellSize() });
		}
		if ((loc.y >= brd.getHeight()/brd.getCellSize() - 1) && delta_loc.y == 1) {
			initHead({ loc.x, 0 - 1 });
		}
		if ((loc.x < 1) && delta_loc.x == -1) {
			initHead({ brd.getWidth() / brd.getCellSize(), loc.y });
		}
		if ((loc.x > brd.getWidth() / brd.getCellSize() - 2) && delta_loc.x == 1) {
			initHead({ 0, loc.y });
		}
		else {
			loc.Add(delta_loc);
		}
}

void Snake::Segment::Follow(const Segment& next) {
	loc = next.loc;
}

Location Snake::Segment::getLoc() {
	return loc;
}
void Snake::Segment::DrawSeg(Board& brd) {
	brd.Draw(loc, c);
	
}

