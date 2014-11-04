#include "Game.h"
#include "BaseRoom.h"
#include "RoomFactory.h"
#include "Direction.h"
#include "Player.h"

#include <iostream>

Game Game::game_singleton;

Game::Game()
{
	createVector();

	roomFactory = new RoomFactory();
	this->player = new Player();

	view = new View(this);

	StartRoom* sr = roomFactory->createStartRoom(nullptr);
	roomVector.at(sr->getLevel()).at(sr->getRow()).at(sr->getColumn()) = sr;
	player->setRoom(sr);


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
}

Player* Game::getPlayer() {
	return this->player;
}

std::vector<std::vector<std::vector<BaseRoom*>>>* Game::getRoomVector() {
	return &roomVector;
}

RoomFactory* Game::getRoomFactory() {
	return roomFactory;
}

bool Game::hasEnd(int level) {
	for (size_t i = 0; i < Game::Instance()->getRoomVector()->at(level).size(); i++)
	{
		for (size_t j = 0; j < Game::Instance()->getRoomVector()->at(level).at(i).size(); j++)
		{
			BaseRoom* br = Game::Instance()->getRoomVector()->at(level).at(i).at(j);
			if (br != nullptr && br->toString() == std::string("endroom"))
			{
				return true;
			}
		}
	}
	return false;
}


int Game::getRoomCount() {
	int count = 0;
	int currentLevel = 0;
	if (this->getPlayer()->getRoom() != nullptr) {
		currentLevel = this->getPlayer()->getRoom()->getLevel();
	}
	for (size_t i = 0; i < Game::Instance()->getRoomVector()->at(currentLevel).size(); i++)
	{
		for (size_t j = 0; j < Game::Instance()->getRoomVector()->at(currentLevel).at(i).size(); j++)
		{
			if (Game::Instance()->getRoomVector()->at(currentLevel).at(i).at(j) != nullptr)
			{
				std::cout << "ROOM FOUND" << std::endl;
				count++;
			}
		}
	}
	if (count == 0) {
		count = 1;
	}

	return count;
}



Game::~Game(void)
{
	delete roomFactory;
}
