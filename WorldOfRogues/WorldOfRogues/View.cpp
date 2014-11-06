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
#include <algorithm>

View::View(Game* game)
{
	this->game = game;
	input = "help";
}

void View::receiveInput()
{
	std::string enterPrefix = "enter door ";
	std::string usePrefix = "use ";
	std::string unequipPrefix = "unequip ";
	std::string takePrefix = "take ";
	std::string attackPrefix = "attack ";

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
			std::cout << "- take [item_number]" << std::endl;
			std::cout << "- attack [monster_number]" << std::endl;
			if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "E") {
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() <= Game::Instance()->getPlayer()->getMaxLevelVisited() &&  Game::Instance()->getPlayer()->getRoom()->getLevel() < 10) { // max level in tower
					std::cout << "- ascend" << std::endl;
				}
			}

			if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "S") {
				if (Game::Instance()->getPlayer()->getRoom()->getLevel() > 0) {
					std::cout << "- descend" << std::endl;
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
		else if (input == "examine room") {
			displayCurrentRoom();
		}
		else if (input == "player_stats") {
			displayPlayerStatistics();
		}
		else if (input.substr(0, attackPrefix.size()) == attackPrefix) {
			attack(attackPrefix, input);
		}
		else if (input.substr(0, usePrefix.size()) == usePrefix) {
			useItem(usePrefix, input);
		}
		else if (input.substr(0, takePrefix.size()) == takePrefix) {
			takeItem(takePrefix, input);
		}
		else if (input.substr(0, unequipPrefix.size()) == unequipPrefix) {
			unequipItem(unequipPrefix, input);
		}
		else if (input.substr(0, enterPrefix.size()) == enterPrefix)
		{
			enterDoor(enterPrefix, input);
		}
		else if(input == "descend") {
			descend();
		}
		else if (input == "ascend")
		{
			ascend();
		}
		else
		{
			std::cout << "Unknown command: '" << input << "'.\n Type 'help' for more information.\n";
		}

		std::cout << "> ";

		std::getline(std::cin, input);
	}
}

void View::gameOver() {
	std::string input2 = "";
	while (input2 != "restart" || input2 != "quit")
	{
		if (input2 == "restart") {
			Game::Instance()->init();
		} else if (input2 == "quit") {

		}


		std::getline(std::cin, input2);
	}
}

void View::attack(std::string prefix, std::string input) {
	std::string monster_number = input.substr(prefix.size(), input.size());
	int monster_number_value = atoi(monster_number.c_str()) - 1;
	if (monster_number_value >= 0 && monster_number_value < Game::Instance()->getPlayer()->getRoom()->getEnemies().size()) {
		BaseEntity* monster = Game::Instance()->getPlayer()->getRoom()->getEnemies().at(monster_number_value);
		if (monster != nullptr) {
			int monsterHPBefore = monster->getHitpoints();
			int monsterHPAfter = Game::Instance()->getPlayer()->attack(monster);
			if (monster->getHitpoints() <= 0) {
				//Delete monster from room
				std::cout << "You've dealt the finishing blow to " << monster->toString() << std::endl;
				std::vector<BaseEntity*>& vec = Game::Instance()->getPlayer()->getRoom()->getEnemies();
				vec.erase(std::remove(vec.begin(), vec.end(), monster), vec.end());
				Game::Instance()->getPlayer()->getRoom()->setEnemies(vec);
				return;
			}
			int playerHPBefore = Game::Instance()->getPlayer()->getHitpoints();
			int playerHPAfter = monster->attack(Game::Instance()->getPlayer());

			if (monsterHPBefore == monsterHPAfter) {
				std::cout << "You've totally missed your target... Try it again with more precision!" << std::endl;
			} else {
				std::cout << "You've dealt " << monsterHPBefore - monsterHPAfter << " damage to " << monster->toString() << ". It has "<< monsterHPAfter << "HP left." << std::endl;
			}

			if (playerHPBefore == playerHPAfter) {
				std::cout << "Because you were so agile, you dodged the attack of " << monster->toString() << ". You lost no HP!" << std::endl;
			} else {
				std::cout << "You took " << playerHPBefore-playerHPAfter<< " damage and currently have " << playerHPAfter << "HP left." << std::endl;
			}

		}
	} else {
		std::cout << "Invalid monster number given. Type 'examine room' to check the items again." << std::endl;
	}
}

void View::ascend() {
	if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "E" && Game::Instance()->getPlayer()->getRoom()->getLevel() <= Game::Instance()->getPlayer()->getMaxLevelVisited() && Game::Instance()->getPlayer()->getRoom()->getLevel() < 10) {
		BaseRoom* newRoom = Game::Instance()->getRoomVector()
			->at(Game::Instance()->getPlayer()->getRoom()->getLevel() + 1)
			.at(Game::Instance()->getPlayer()->getRoom()->getRow())
			.at(Game::Instance()->getPlayer()->getRoom()->getColumn());

		if (newRoom == nullptr) {
			newRoom = Game::Instance()->getRoomFactory()->createStartRoom(Game::Instance()->getPlayer()->getRoom());
			Game::Instance()->getRoomVector()
				->at(Game::Instance()->getPlayer()->getRoom()->getLevel() + 1)
				.at(Game::Instance()->getPlayer()->getRoom()->getRow())
				.at(Game::Instance()->getPlayer()->getRoom()->getColumn()) = newRoom;
		}

		Game::Instance()->getPlayer()->setRoom(newRoom);
		Game::Instance()->getPlayer()->setMaxLevelVisited(newRoom->getLevel());
		std::cout << "You've ascended to level " << Game::Instance()->getPlayer()->getLevel() << std::endl;
	} else {
		std::cout << "You can't ascend here!" << std::endl;
	}
}

void View::descend() {
	if (Game::Instance()->getPlayer()->getRoom()->getSymbol() == "S"  && Game::Instance()->getPlayer()->getRoom()->getLevel() > 0) {
		BaseRoom* newRoom = Game::Instance()->getRoomVector()
			->at(Game::Instance()->getPlayer()->getRoom()->getLevel() - 1)
			.at(Game::Instance()->getPlayer()->getRoom()->getRow())
			.at(Game::Instance()->getPlayer()->getRoom()->getColumn());

		if (newRoom == nullptr) {
			std::cout << "SHOULD NOT HAPPEN" << std::endl;
		}

		Game::Instance()->getPlayer()->setRoom(newRoom);
		std::cout << "You've descended into level " << Game::Instance()->getPlayer()->getLevel() << std::endl;
	} else {
		std::cout << "You can't descend here!" << std::endl;
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

void View::takeItem(std::string prefix, std::string input) {
	std::string item_number = input.substr(prefix.size(), input.size());
	int item_number_value = atoi(item_number.c_str()) - 1;
	if (item_number_value >= 0 && item_number_value < Game::Instance()->getPlayer()->getRoom()->getItems().size()) {
		BaseItem* item = Game::Instance()->getPlayer()->getRoom()->getItems().at(item_number_value);
		if (item != nullptr) {
			std::cout << "Taking item: " << Game::Instance()->getPlayer()->getRoom()->getItems().at(item_number_value)->toString() << std::endl;
			//Add to inventory
			Game::Instance()->getPlayer()->getInventory()->addItem(item);

			//Remove from items in room
			std::vector<BaseItem*>& vec = Game::Instance()->getPlayer()->getRoom()->getItems();
			vec.erase(std::remove(vec.begin(), vec.end(), item), vec.end());
			Game::Instance()->getPlayer()->getRoom()->setItems(vec);

		}
	} else {
		std::cout << "Invalid item number given. Type 'examine room' to check the items again." << std::endl;
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



View::~View()
{
}
