#include "Game.h"
#include "BaseRoom.h"
#include "RoomFactory.h"
#include "Direction.h"

#include <iostream>


Game::Game()
{
	createVector();
	view = new View(this);
	view->receiveInput();
}

void Game::createVector()
{
	int width = 10;
	int height = 10;
	int depth = 10;

	roomVector.resize(width);
	for (int a = 0; a < width; a++){
		roomVector[a].resize(height);
		for (int b = 0; b < height; b++) {
			roomVector[a][b].resize(depth);
		}
	}
	RoomFactory rf;

	//roomVector[1][2][3] = new BaseRoom(1, 2, 3);
	//roomVector[1][3][3] = rf.createRoom(roomVector[1][2][3], Direction::East);

	roomVector[1][2][3] = new RegularRoom(1, 2, 3);
	roomVector[1][5][4] = new EndRoom(1, 5, 4);
	roomVector[1][3][7] = new BossRoom(1, 3, 7);
}



Game::~Game(void)
{
}
