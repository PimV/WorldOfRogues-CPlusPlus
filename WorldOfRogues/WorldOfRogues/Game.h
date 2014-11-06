#pragma once
#include <vld.h> 
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
	void init();
	void cleanup();
	Player* getPlayer();
	void createVector();
	std::vector<std::vector<std::vector<BaseRoom*>>>* getRoomVector();
	RoomFactory* getRoomFactory();

	void gameOver();

	bool hasEnd(int level);

	int getRoomCount();


	~Game();


	static Game* Instance() {
		return &game_singleton;
	};


private:
	int currentLevel;
	int endRoomsFound;
	Player* player;
	View *view;
	RoomFactory* roomFactory;
	std::vector<std::vector<std::vector<BaseRoom*>>> roomVector;
	void displayMap();
	static Game game_singleton;
};



