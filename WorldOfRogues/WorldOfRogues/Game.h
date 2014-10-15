#pragma once
#include "View.h"

#include <string>
#include <vector>
#include <iostream>

class BaseRoom;
class Player;
class RoomFactory;

class Game
{
public:
	Game();
	Player* getPlayer();
	~Game();
	std::vector<std::vector<std::vector<BaseRoom*> > > roomVector;
	RoomFactory* rf;

private:
	Player* player;
	View *view;
	void createVector();
	void displayMap();
};



