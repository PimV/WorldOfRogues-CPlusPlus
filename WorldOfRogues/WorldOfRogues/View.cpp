#include "View.h"
#include "RoomFactory.h"
#include "Game.h"
#include "Player.h"
#include "BaseRoom.h"
#include "Direction.h"
#include "Player_Equipment.h"
#include "Player_Inventory.h"
#include "BaseItem.h"
#include "Weapon.h"
#include "Shield.h"
#include "Platebody.h"
#include "Platelegs.h"
#include "Helmet.h"

View::View(Game* game)
{
	this->game = game;

	displayIntroMessage();

	input = "help";
}

void View::receiveInput()
{
	std::string enterPrefix = "enter door ";
	std::string usePrefix = "use ";
	std::string unequipPrefix = "unequip ";

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
			std::cout << "- equipment" << std::endl;
			std::cout << "- player_stats" << std::endl;
			std::cout << "- inventory" << std::endl;
			std::cout << "- use [item]" << std::endl;
			std::cout << "- unequip [equipment_item]" << std::endl;
			std::cout << "- addhelm" << std::endl;
			if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "E") {
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() > 0) {
					std::cout << "- descend" << std::endl;
				}
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() < 3) { // max level in tower
					std::cout << "- ascend" << std::endl;
				}
			}

			if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "S") {
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
		else if (input == "equipment") {
			displayEquipment();
		}
		else if (input == "inventory") {
			displayInventory();
		}
		else if (input == "addhelm") {
			Game::Instance()->getPlayer()->getInventory()->addItem(new Helmet(),-1);
		} 
		else if (input == "examine room") {
			displayCurrentRoom();
		}
		else if (input == "player_stats") {
			displayPlayerStatistics();
		}
		else if (input.substr(0, usePrefix.size()) == usePrefix) {
			useItem(usePrefix, input);
		}
		else if (input.substr(0, unequipPrefix.size()) == unequipPrefix) {
			unequipItem(unequipPrefix, input);
		}
		else if (input.substr(0, enterPrefix.size()) == enterPrefix)
		{
			enterDoor(enterPrefix, input);
		}
		else if((Game::Instance()->getPlayer()->getRoom()->getSymbol() == "S" ||
			Game::Instance()->getPlayer()->getRoom()->getSymbol() == "E") 
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

		else if ((Game::Instance()->getPlayer()->getRoom()->getSymbol() == "S" ||
			Game::Instance()->getPlayer()->getRoom()->getSymbol() == "E") 
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

void View::unequipItem(std::string prefix, std::string input) {
	std::string item = input.substr(prefix.size(), input.size());
	std::string itemFound = Game::Instance()->getPlayer()->getEquipment()->hasItem(item);

	if (itemFound == "weapon") {
		Game::Instance()->getPlayer()->getInventory()->addItem(dynamic_cast<BaseItem*>(Game::Instance()->getPlayer()->getEquipment()->getWeapon()), 1);
		Game::Instance()->getPlayer()->getEquipment()->setWeapon(nullptr);
		std::cout << "Unequipped weapon: " << item << ", it's back in your inventory now." << std::endl;
	} else if (itemFound == "shield") {
		Game::Instance()->getPlayer()->getInventory()->addItem(dynamic_cast<BaseItem*>(Game::Instance()->getPlayer()->getEquipment()->getShield()),1);
		Game::Instance()->getPlayer()->getEquipment()->setShield(nullptr);
		std::cout << "Unequipped shield: " << item << ", it's back in your inventory now." << std::endl;
	} else if (itemFound == "platebody") {
		Game::Instance()->getPlayer()->getInventory()->addItem(dynamic_cast<BaseItem*>(Game::Instance()->getPlayer()->getEquipment()->getPlatebody()),1);
		Game::Instance()->getPlayer()->getEquipment()->setPlatebody(nullptr);
		std::cout << "Unequipped platebody: " << item << ", it's back in your inventory now." << std::endl;
	} else if (itemFound == "platelegs") {
		Game::Instance()->getPlayer()->getInventory()->addItem(dynamic_cast<BaseItem*>(Game::Instance()->getPlayer()->getEquipment()->getPlatelegs()),1);
		Game::Instance()->getPlayer()->getEquipment()->setPlatelegs(nullptr);
		std::cout << "Unequipped platelegs: " << item << ", it's back in your inventory now." << std::endl;
	} else if (itemFound == "helmet") {
		Game::Instance()->getPlayer()->getInventory()->addItem(dynamic_cast<BaseItem*>(Game::Instance()->getPlayer()->getEquipment()->getHelmet()),1);
		Game::Instance()->getPlayer()->getEquipment()->setHelmet(nullptr);
		std::cout << "Unequipped helmet: " << item << ", it's back in your inventory now." << std::endl;
	} else if (itemFound == "false") {
		std::cout << "You are currently not wearing a(n) " << item << "." << std::endl;
	}

}

void View::useItem(std::string prefix, std::string input) {
	std::string item = input.substr(prefix.size(), input.size());

	if (Game::Instance()->getPlayer()->getInventory()->hasItem(item)) {
		Game::Instance()->getPlayer()->getInventory()->getItem(item)->use(Game::Instance()->getPlayer());
		std::cout << "Used item: " << item << std::endl;
	} else {
		std::cout << "Item not found in inventory" << std::endl;
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

	std::cout << std::endl;

	for (size_t i = 0; i < Game::Instance()->getRoomVector()->at(currentLevel).size(); i++)
	{
		(i == Game::Instance()->getPlayer()->getRoom()->getColumn()) ? std::cout << " * " : std::cout << "   ";
	}

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
	std::cout << std::endl << "Level " << currentLevel << std::endl;
	std::cout << "Information: " << std::endl 
			<< "R - Regular Room" << std::endl 
			<< "B - Boss room" << std::endl 
			<< "E - End room" << std::endl 
			<< "S - Start room" << std::endl;
}

void View::displayEquipment() {
	std::cout << "Equipment: " << std::endl << std::endl;;
	std::cout << Game::Instance()->getPlayer()->getEquipment()->toString() << std::endl;
}

void View::displayInventory() {
	std::cout << "Inventory: " << std::endl << std::endl;;
	std::cout << Game::Instance()->getPlayer()->getInventory()->toString() << std::endl;
}

void View::displayPlayerStatistics() {
	std::cout << "Player statistics: " << std::endl << std::endl;

	std::cout << Game::Instance()->getPlayer()->toString() << std::endl;
}

void View::displayCurrentRoom() {
	std::cout << "Current room: " << std::endl << std::endl;;

	std::cout << Game::Instance()->getPlayer()->getRoom()->toString() << std::endl;
}

void View::displayIntroMessage()
{
	std::cout << "Welcome to the World of Rogues!" << std::endl << std::endl ;
	std::cout << "Your on a quest to slay the demon that resides at the top of the tower. ";
	std::cout << "On your way to the top you shall encounter many obstacles that will prevent you from reaching your goal. ";
	std::cout << "Make sure to collect all the items along the way and equip them before entering battle." << std::endl << std::endl;

	std::cout << "You have been given a map that will help guide you through the tower. However, the map will only display the rooms you've been in and which doors you can enter." << std::endl << std::endl;
}


View::~View()
{
}
