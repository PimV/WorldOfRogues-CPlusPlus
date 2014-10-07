#include "Game.h"
#include "BaseRoom.h"

#include <iostream>
#include <vector>

using namespace std;

Game::Game(void)
{
}

void main() {

	int width = 10;
	int height = 10;
	int depth = 10;

	std::vector<std::vector<std::vector<BaseRoom*> > > roomVector;
	
	roomVector.resize(width);
	for (int a = 0; a < width; a++){
		roomVector[a].resize(height);
		for (int b = 0; b < height; b++) {
			roomVector[a][b].resize(depth);
		}
	}

	roomVector[1][2][3] = new BaseRoom();
	BaseRoom* room = roomVector[1][2][3];
	std::cout << sizeof(room);

	cin.get();
}


Game::~Game(void)
{
}
