/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>
#include "SpriteCodex.h"

Game::Game(MainWindow& wnd)
	:
	wnd(wnd),
	gfx(wnd),
	brd(gfx),
	snek({ 1,1 }),
	goal(brd),
	rng(std::random_device()()),
	xDist(0, brd.getWidth() / brd.getCellSize() - 2),
	yDist(0, brd.getHeight() / brd.getCellSize() - 1)
{
	for (int i = 0; i < nObs; i++) {
		obs[i].initObs({ xDist(rng),yDist(rng) });
	}
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (wnd.kbd.KeyIsPressed(VK_RETURN)) {
		start = true;
	}
	if(!start) {
		SpriteCodex::DrawTitle(300, 200, gfx);
	}
	if (start) {
		GameOver = snek.getLoopState();

		for (int i = 0; i < nObsCounter; i++) {
			if (obs[i].CheckCollision(snek.getHeadLocation(), obs[i].GetLocation())) {
				GameOver = true;
			}
		}
		if (!GameOver) {
			if ((wnd.kbd.KeyIsPressed(VK_UP)) && delta_loc.y != 1) {
				delta_loc = { 0,-1 };
			}
			if ((wnd.kbd.KeyIsPressed(VK_LEFT)) && delta_loc.x != 1) {
				delta_loc = { -1,0 };
			}
			if ((wnd.kbd.KeyIsPressed(VK_DOWN)) && delta_loc.y != -1) {
				delta_loc = { 0, 1 };
			}
			if ((wnd.kbd.KeyIsPressed(VK_RIGHT)) && delta_loc.x != -1) {
				delta_loc = { 1, 0 };
			}
			if (goal.CheckCollision(snek.getHeadLocation(), goal.GetLocation())) {
				snek.Grow();
				interval--;
				for (int i = 0; i < nObs; i++) {
					goal.initGoalLoc(obs[i].GetLocation());
				}
				goal.DrawGoal(brd);
				obs[nObsCounter].DrawObs(brd);
				counter2++;
				nObsCounter++;
			}
			counter++;
			if (counter >= interval) {
				snek.Moveby(delta_loc, brd);
				counter = 0;
			}
		}
	}
}

void Game::ComposeFrame()
{
	if (!GameOver) {
		snek.Draw(brd);
		goal.DrawGoal(brd);
		for (int i = 0; i < nObsCounter; i++) {
			obs[i].DrawObs(brd);
		}
}
	else {
		snek.Draw(brd);
		goal.DrawGoal(brd);
		for (int i = 0; i < nObsCounter; i++) {
			obs[i].DrawObs(brd);
		}
		snek.DrawHead(brd);
		SpriteCodex::DrawGameOver(400 - 84 / 2, 300 - 64 / 2, gfx);
	}

}
