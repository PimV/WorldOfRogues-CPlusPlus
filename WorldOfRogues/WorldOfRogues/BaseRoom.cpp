#include "BaseRoom.h"
#include <time.h>
#include "Game.h"
#include <vector>

BaseRoom::BaseRoom(int level, int row, int column)
{
	this->row = row;
	this->column = column;
	this->level = level;

	disableEastDoor();
	disableNorthDoor();
	disableSouthDoor();
	disableWestDoor();
}

#pragma region Room Properties
void BaseRoom::setRow(int row) {
	this->row = row;
}
void BaseRoom::setColumn(int column) {
	this->column = column;
}
void BaseRoom::setLevel(int level) {
	this->level = level;
}
void BaseRoom::setSymbol(char* c) 
{
	this->symbol = c;
}
int BaseRoom::getRow() {
	return this->row;
}
int BaseRoom::getColumn() {
	return this->column;
}
int BaseRoom::getLevel() {
	return this->level;
}
char* BaseRoom::getSymbol() {
	return this->symbol;
}
#pragma endregion

#pragma region Rooms
void BaseRoom::setNorthRoom(BaseRoom* room) {
	this->northRoom = room;
}
void BaseRoom::setSouthRoom(BaseRoom* room) {
	this->southRoom = room;
}
void BaseRoom::setEastRoom(BaseRoom* room) {
	this->eastRoom = room;
}
void BaseRoom::setWestRoom(BaseRoom* room) {
	this->westRoom = room;
}
BaseRoom* BaseRoom::getNorthRoom() {
	return this->northRoom;
}
BaseRoom* BaseRoom::getSouthRoom() {
	return this->southRoom;
}
BaseRoom* BaseRoom::getEastRoom() {
	return this->eastRoom;
}
BaseRoom* BaseRoom::getWestRoom() {
	return this->westRoom;
}
#pragma endregion

#pragma region Doors

void BaseRoom::generateDoors() {
	srand(time(NULL));
	int loopCount = (2*(4 + Game::Instance()->getRoomCount())) / (Game::Instance()->getRoomCount());
	for (int i = 0; i < loopCount; i++) {
		int randomDoorGen = rand() % 4;
		switch(randomDoorGen) {
		case 0:
			if (this->row != 0) enableNorthDoor();
			break;
		case 1:
			if (this->column != 9) enableEastDoor();
			break;
		case 2:
			if (this->row != 9) enableSouthDoor();
			break;
		case 3:
			if (this->column != 0) enableWestDoor();
			break;
		}
	}

	if (row == 10) {
		disableSouthDoor();
	} else if (row == 0) {
		disableNorthDoor();
	}

	if (column == 10) {
		disableEastDoor();
	}
	else if (column == 0) {
		disableWestDoor();
	}

	if (getNorthRoom() != nullptr) {
		getNorthRoom()->enableSouthDoor();
		enableNorthDoor();
	}

	if (getSouthRoom() != nullptr) {
		getSouthRoom()->enableNorthDoor();
		enableSouthDoor();
	}

	if (getWestRoom() != nullptr) {
		getWestRoom()->enableEastDoor();
		enableWestDoor();
	}

	if (getEastRoom() != nullptr) {
		getEastRoom()->enableWestDoor();
		enableEastDoor();
	}

	if (getDoorCount() == 0) {
		generateDoors();
	}
}

bool BaseRoom::hasNorthDoor() {
	return this->northDoor;
}

bool BaseRoom::hasSouthDoor() {
	return this->southDoor;
}	

bool BaseRoom::hasWestDoor() {
	return this->westDoor;
}
bool BaseRoom::hasEastDoor() {
	return this->eastDoor;
}

void BaseRoom::enableNorthDoor() {
	this->northDoor = true;
}

void BaseRoom::enableSouthDoor() {
	this->southDoor = true;
}

void BaseRoom::enableWestDoor() {
	this->westDoor = true;
}

void BaseRoom::enableEastDoor() {
	this->eastDoor = true;
}

void BaseRoom::disableNorthDoor() {
	this->northDoor = false;
}

void BaseRoom::disableSouthDoor() {
	this->southDoor = false;
}

void BaseRoom::disableWestDoor() {
	this->westDoor = false;
}

void BaseRoom::disableEastDoor() {
	this->eastDoor = false;
}

int BaseRoom::getDoorCount() {
	int doorCount = 0;
	if (this->northDoor) {
		++doorCount;
	}

	if (this->southDoor) {
		++doorCount;
	}

	if (this->eastDoor) {
		++doorCount;
	}

	if (this->westDoor) {
		++doorCount;
	}

	return doorCount;
}

std::string BaseRoom::getAvailableDoorString() {
	std::string doors = "(";
	if (this->hasNorthDoor()) {
		doors += "north,";
	}

	if (this->southDoor) {
		doors += "south,";
	}

	if (this->eastDoor) {
		doors += "east,";
	}

	if (this->westDoor) {
		doors += "west,";
	}

	doors = doors.substr(0, doors.length()-1);

	doors += ")";
	return doors;
}

#pragma endregion

void BaseRoom::setEnemies(std::vector<BaseEntity*> enemies)
{
	this->enemies = enemies;
}

void BaseRoom::setItems(std::vector<BaseItem*> items)
{
	this->items = items;
}

void BaseRoom::addEnemies(std::vector<BaseEntity*> enemies)
{
	this->enemies.insert(this->enemies.end(), enemies.begin(), enemies.end());
}

void BaseRoom::addItems(std::vector<BaseItem*> items)
{
	this->items.insert(this->items.end(), items.begin(), items.end());
}

std::vector<BaseEntity*> BaseRoom::getEnemies()
{
	return this->enemies;
}

std::vector<BaseItem*> BaseRoom::getItems()
{
	return this->items;
}

void BaseRoom::addEnemy(BaseEntity* entity)
{
	this->enemies.push_back(entity);
}

void BaseRoom::addItem(BaseItem* item)
{
	this->items.push_back(item);
}


std::string BaseRoom::toString() {
	std::string currentRoom = "";
	if (this->enemies.size() > 0) {
		currentRoom.append("Enemies: \n");
		int enemySelectionNumber = 1;
		for(BaseEntity* e : this->enemies) {
			currentRoom.append("\t" + std::to_string(enemySelectionNumber) + ". " +  e->toString() + " (lvl: " + std::to_string(e->getLevel()) + ") \n");
			enemySelectionNumber++;
		}
	}

	if (this->items.size() > 0) {
		currentRoom.append("Items: \n");
		for(BaseItem* e : this->items) {
			currentRoom.append("\t" + e->toString() + "[" + std::to_string(e->getCount()) + "] \n");
		}
	}
	return currentRoom;

}

BaseRoom::~BaseRoom(void)
{
}
