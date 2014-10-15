#include "View.h"
#include "RoomFactory.h"
#include "Game.h"
#include "Player.h"
#include "BaseRoom.h"
#include "Direction.h"

View::View(Game* game)
{
	this->game = game;
	input = "help";
}

void View::receiveInput()
{
	while (input != "quit")
	{
		if (input == "help")
		{
			std::cout << "Please use one of the following commands:" << std::endl;
			std::cout << "- map" << std::endl;
			std::cout << "- examine room" << std::endl;
			std::cout << "- quit" << std::endl;
			std::cout << "- enter door" << std::endl;
		}
		else if (input == "map")
		{
			displayMap();
		}
		else if (input == "enter door")
		{
			enterDoor();
		}
		else
		{
			std::cout << "Unknown command: '" << input << "'.\n Type 'help' for more information.\n";
		}

		std::cout << "\n> ";

		std::getline(std::cin, input);
	}
}

void View::enterDoor() {
	BaseRoom* currentRoom = this->game->getPlayer()->getRoom();

	BaseRoom* destinationRoom;
	std::cout << "Possible doors: " + currentRoom->getAvailableDoorString() << std::endl;
	std::string input2 = "";
	std::getline(std::cin, input2);
	if (input2 == "north") {
		if (currentRoom->hasNorthDoor()) {
			if (currentRoom->getNorthRoom() == nullptr) {
				destinationRoom = this->game->rf->createRoom(currentRoom, Direction::North);
				this->game->roomVector[destinationRoom->getLevel()][destinationRoom->getRow()][destinationRoom->getColumn()] = destinationRoom;
			} 
			this->game->getPlayer()->setRoom(currentRoom->getNorthRoom());
		}
	} else if (input2 == "east") {
		if (currentRoom->hasEastDoor()) {
			if (currentRoom->getEastRoom() == nullptr) {
				destinationRoom = this->game->rf->createRoom(currentRoom, Direction::East);
				this->game->roomVector[destinationRoom->getLevel()][destinationRoom->getRow()][destinationRoom->getColumn()] = destinationRoom;
			} 
			this->game->getPlayer()->setRoom(currentRoom->getEastRoom());
		}
	} else if (input2 == "south") {
		if (currentRoom->hasSouthDoor()) {
			if (currentRoom->getSouthRoom() == nullptr) {
				destinationRoom = this->game->rf->createRoom(currentRoom, Direction::South);
				this->game->roomVector[destinationRoom->getLevel()][destinationRoom->getRow()][destinationRoom->getColumn()] = destinationRoom;
			} 
			this->game->getPlayer()->setRoom(currentRoom->getSouthRoom());
		}
	} else if (input2 == "west") {
		if (currentRoom->hasWestDoor()) {
			if (currentRoom->getWestRoom() == nullptr) {
				destinationRoom = this->game->rf->createRoom(currentRoom, Direction::West);
				this->game->roomVector[destinationRoom->getLevel()][destinationRoom->getRow()][destinationRoom->getColumn()] = destinationRoom;
			} 
			this->game->getPlayer()->setRoom(currentRoom->getWestRoom());
		}
	}
}

void View::displayMap()
{
	// change currentLevel
	size_t currentLevel = 0;
	for (size_t i = 0; i < this->game->roomVector[currentLevel].size(); i++)
	{
		std::string northDoors = "";
		std::string roomsAndDoors = "";
		std::string southDoors = "";

		for (size_t j = 0; j < this->game->roomVector[currentLevel][i].size(); j++)
		{

			if (this->game->roomVector[currentLevel][i][j] != nullptr)
			{
				if (this->game->roomVector[currentLevel][i][j]->hasWestDoor()) {
					roomsAndDoors += "-";
				} else {
					roomsAndDoors += " ";
				}
				roomsAndDoors += this->game->roomVector[currentLevel][i][j]->getSymbol();
				//std::cout << this->game->roomVector[currentLevel][i][j]->getSymbol();
				if (this->game->roomVector[currentLevel][i][j]->hasEastDoor()) {
					roomsAndDoors += "-";
					//std::cout << "-";
				} else {
					roomsAndDoors += " ";
					//std::cout << " ";
				}



				if (this->game->roomVector[currentLevel][i][j]->hasSouthDoor()) {
					southDoors += " | ";
				} else {
					southDoors += "   ";
				}

				if (this->game->roomVector[currentLevel][i][j]->hasNorthDoor()) {
					northDoors += " | ";
				} else {
					northDoors += "   ";
				}
			}
			else
			{
				northDoors += "   ";
				southDoors += "   ";
				roomsAndDoors += " . ";
				//std::cout << ". ";
			}
		}
		// print doors:
		std::cout << northDoors << std::endl << roomsAndDoors << std::endl << southDoors << std::endl;
		//std::cout << std::endl << southDoors << std::endl;

	}
}


View::~View()
{
}
