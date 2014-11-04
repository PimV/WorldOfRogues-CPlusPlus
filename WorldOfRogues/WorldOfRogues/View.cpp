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
	std::string enterPrefix = "enter door ";

	while (input != "quit")
	{
		if (input == "help")
		{
			std::cout << "Please use one of the following commands:" << std::endl;
			std::cout << "- map" << std::endl;
			std::cout << "- examine room" << std::endl;
			std::cout << "- quit" << std::endl;
			std::cout << "- enter door" << std::endl;
			std::cout << "- current_level" << std::endl;
			if (Game::Instance()->getPlayer()->getRoom()->toString() == std::string("endroom")) {
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() > 0) {
					std::cout << "- descend" << std::endl;
				}
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() < 3) { // max level in tower
					std::cout << "- ascend" << std::endl;
				}
			}

			if (Game::Instance()->getPlayer()->getRoom()->toString() == std::string("startroom")) {
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() > 0) {
					std::cout << "- descend" << std::endl;
				}
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() < Game::Instance()->getPlayer()->getMaxLevelVisited()) { 
					std::cout << "- ascend" << std::endl;
				}
			}
		}
		else if (input == "current_level") {
			std::cout << "You are now on level: " << Game::Instance()->getPlayer()->getRoom()->getLevel() << std::endl;
		}
		else if (input == "map")
		{
			displayMap();
		}
		else if (input.substr(0, enterPrefix.size()) == enterPrefix)
		{
			enterDoor(enterPrefix, input);
		}
		else if((Game::Instance()->getPlayer()->getRoom()->toString() == std::string("startroom") ||
			Game::Instance()->getPlayer()->getRoom()->toString() == std::string("endroom")) 
			&& input == "descend") {
				BaseRoom* newRoom = Game::Instance()->getRoomVector()
					->at(Game::Instance()->getPlayer()->getRoom()->getLevel() - 1)
					.at(Game::Instance()->getPlayer()->getRoom()->getRow())
					.at(Game::Instance()->getPlayer()->getRoom()->getColumn());

				if (newRoom == nullptr) {
					std::cout << "SHOULD NOT HAPPEN" << std::endl;
				}

				Game::Instance()->getPlayer()->setRoom(newRoom);

		}

		else if ((Game::Instance()->getPlayer()->getRoom()->toString() == std::string("startroom") ||
			Game::Instance()->getPlayer()->getRoom()->toString() == std::string("endroom")) 
			&& input == "ascend") {
				BaseRoom* newRoom = Game::Instance()->getRoomVector()
					->at(Game::Instance()->getPlayer()->getRoom()->getLevel() + 1)
					.at(Game::Instance()->getPlayer()->getRoom()->getRow())
					.at(Game::Instance()->getPlayer()->getRoom()->getColumn());

				if (newRoom == nullptr) {
					std::cout << "Creating new start room" << std::endl;
					newRoom = Game::Instance()->getRoomFactory()->createStartRoom(Game::Instance()->getPlayer()->getRoom());
					Game::Instance()->getRoomVector()
						->at(Game::Instance()->getPlayer()->getRoom()->getLevel() + 1)
						.at(Game::Instance()->getPlayer()->getRoom()->getRow())
						.at(Game::Instance()->getPlayer()->getRoom()->getColumn()) = newRoom;
				}

				Game::Instance()->getPlayer()->setRoom(newRoom);
				Game::Instance()->getPlayer()->setMaxLevelVisited(newRoom->getLevel());

		}
		else
		{
			std::cout << "Unknown command: '" << input << "'.\n Type 'help' for more information.\n";
		}

		std::cout << "\n> ";

		std::getline(std::cin, input);
	}
}

void View::enterDoor(std::string prefix, std::string input) {
	std::string direction = input.substr(prefix.size(), input.size());

	BaseRoom* currentRoom = this->game->getPlayer()->getRoom();
	BaseRoom* destinationRoom = nullptr;

	Game::Instance()->getRoomFactory()->fixDoors(currentRoom);

	bool wrongDirection = false;

	if (direction == "north") {
		if (currentRoom->hasNorthDoor()) {
			if (currentRoom->getNorthRoom() == nullptr) {
				destinationRoom = Game::Instance()->getRoomFactory()->createRoom(currentRoom, Direction::North);
				Game::Instance()->getRoomFactory()->fixDoors(destinationRoom);
				Game::Instance()->getRoomVector()->at(destinationRoom->getLevel()).at(destinationRoom->getRow()).at(destinationRoom->getColumn()) = destinationRoom;

			}
			this->game->getPlayer()->setRoom(currentRoom->getNorthRoom());
		}
		else {
			wrongDirection = true;
		}
	}
	else if (direction == "east") {
		if (currentRoom->hasEastDoor()) {
			if (currentRoom->getEastRoom() == nullptr) {
				destinationRoom = Game::Instance()->getRoomFactory()->createRoom(currentRoom, Direction::East);
				Game::Instance()->getRoomFactory()->fixDoors(destinationRoom);
				Game::Instance()->getRoomVector()->at(destinationRoom->getLevel()).at(destinationRoom->getRow()).at(destinationRoom->getColumn()) = destinationRoom;
			}
			this->game->getPlayer()->setRoom(currentRoom->getEastRoom());
		}
		else {
			wrongDirection = true;
		}
	}
	else if (direction == "south") {
		if (currentRoom->hasSouthDoor()) {
			if (currentRoom->getSouthRoom() == nullptr) {
				destinationRoom = Game::Instance()->getRoomFactory()->createRoom(currentRoom, Direction::South);
				Game::Instance()->getRoomFactory()->fixDoors(destinationRoom);
				Game::Instance()->getRoomVector()->at(destinationRoom->getLevel()).at(destinationRoom->getRow()).at(destinationRoom->getColumn()) = destinationRoom;
			}
			this->game->getPlayer()->setRoom(currentRoom->getSouthRoom());
		}
		else {
			wrongDirection = true;
		}
	}
	else if (direction == "west") {
		if (currentRoom->hasWestDoor()) {
			if (currentRoom->getWestRoom() == nullptr) {
				destinationRoom = Game::Instance()->getRoomFactory()->createRoom(currentRoom, Direction::West);
				Game::Instance()->getRoomFactory()->fixDoors(destinationRoom);
				Game::Instance()->getRoomVector()->at(destinationRoom->getLevel()).at(destinationRoom->getRow()).at(destinationRoom->getColumn()) = destinationRoom;
			}
			this->game->getPlayer()->setRoom(currentRoom->getWestRoom());
		}
		else {
			wrongDirection = true;
		}
	}

	Game::Instance()->getRoomFactory()->fixDoors(destinationRoom);
	Game::Instance()->getRoomFactory()->fixDoors(currentRoom);

	if (wrongDirection) {
		std::cout << "You keep searching for a door in the " << direction << ", but failed to find one." << std::endl;
	}
	displayMap();
}

void View::displayMap()
{
	// change currentLevel
	size_t currentLevel = Game::Instance()->getPlayer()->getRoom()->getLevel();

	std::cout << std::endl << "Level " << currentLevel << std::endl;
	for (size_t i = 0; i < Game::Instance()->getRoomVector()->at(currentLevel).size(); i++)
	{
		(i == Game::Instance()->getPlayer()->getRoom()->getColumn()) ? std::cout << " * " : std::cout << "   ";
	}

	std::cout << std::endl;
	for (size_t i = 0; i < Game::Instance()->getRoomVector()->at(currentLevel).size(); i++)
	{
		std::string northDoors = "";
		std::string roomsAndDoors = "";
		std::string southDoors = "";
		std::string currentRow = "";
		for (size_t j = 0; j < Game::Instance()->getRoomVector()->at(currentLevel).at(i).size(); j++)
		{
			if (Game::Instance()->getRoomVector()->at(currentLevel).at(i).at(j) != nullptr)
			{
				BaseRoom* currentRoom = Game::Instance()->getRoomVector()->at(currentLevel).at(i).at(j);

				//if (currentRoom->hasWestDoor()) {
				//	roomsAndDoors += "-";
				//} else {
				//	roomsAndDoors += " ";
				//}
				//roomsAndDoors += currentRoom->getSymbol();
				////std::cout << this->game->roomVector[currentLevel][i][j]->getSymbol();
				//if (currentRoom->hasEastDoor()) {
				//	roomsAndDoors += "-";
				//	//std::cout << "-";
				//} else {
				//	roomsAndDoors += " ";
				//	//std::cout << " ";
				//}

				//if (currentRoom->hasSouthDoor()) {
				//	southDoors += " | ";
				//} else {
				//	southDoors += "   ";
				//}

				//if (currentRoom->hasNorthDoor()) {
				//	northDoors += " | ";
				//} else {
				//	northDoors += "   ";
				//}

				(currentRoom->hasWestDoor()) ? roomsAndDoors += "-" : roomsAndDoors += " ";
				roomsAndDoors += currentRoom->getSymbol();
				(currentRoom->hasEastDoor()) ? roomsAndDoors += "-" : roomsAndDoors += " ";
				(currentRoom->hasSouthDoor()) ? southDoors += " | " : southDoors += "   ";
				(currentRoom->hasNorthDoor()) ? northDoors += " | " : northDoors += "   ";
				(Game::Instance()->getPlayer()->getRoom()->getRow() == currentRoom->getRow()) ? currentRow = "*" : currentRow = "";
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
		std::cout << northDoors << std::endl << roomsAndDoors << currentRow << std::endl << southDoors << std::endl;
		//std::cout << std::endl << southDoors << std::endl;

	}
}


View::~View()
{
}
