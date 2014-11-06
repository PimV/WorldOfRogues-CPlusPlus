#include "Game.h"
#include "BaseRoom.h"
#include "RoomFactory.h"
#include "Direction.h"
#include "Player.h"
#include "EntityFactory.h"

#include <iostream>

Game Game::game_singleton;

Game::Game()
{
	init();
}

void Game::cleanup() {
	delete this->roomFactory;
	delete this->player;
	delete this->view;

	for(auto itr = this->roomVector.begin(); itr != this->roomVector.end(); itr++)
	{
		itr = this->roomVector.erase(itr);
	}

}

void Game::init() {
	cleanup();
	createVector();

	roomFactory = new RoomFactory();
	this->player = dynamic_cast<Player*>(EntityFactory::createEntity(EntityType::Player));
	this->player->setLevel(1);

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
			if (br != nullptr && br->getSymbol() == "E")
			{
				return true;
			}
		}
	}
	return false;
}

void Game::gameOver() {
	std::cout << "Oh dear, you are dead! Type 'restart' in order to replay, or 'quit' to exit game." << std::endl;
	view->gameOver();
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
