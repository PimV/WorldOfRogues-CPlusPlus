#include "RoomFactory.h"
#include "Direction.h"
#include <random>
#include <iostream>
#include <time.h>
#include "Game.h"
#include "ItemFactory.h"
#include "EntityFactory.h"


RoomFactory::RoomFactory()
{
}
RoomFactory::~RoomFactory(void)
{
}

BaseRoom* RoomFactory::createRoom(BaseRoom* prevRoom, Direction to) {
	BaseRoom* br;// = new BaseRoom(-1,-1,-1);

	std::random_device dev;
	std::default_random_engine dre(dev());

	// random amount
	std::uniform_int_distribution<int> dist1(Game::Instance()->getRoomCount(), 20);
	int randomRoomNumber = dist1(dre);
	switch(randomRoomNumber) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		br = new RegularRoom(-1, -1, -1);
		break;
	case 19: 
		br = new BossRoom(-1,-1,-1);
		break;
	case 20: 
		br = new EndRoom(-1,-1,-1);
		break;
	default:
		br = new RegularRoom(-1, -1, -1);
		break;
	}

	std::uniform_int_distribution<int> dist2(1, 10);
	int randomTrapNumber = dist2(dre);

	if (randomTrapNumber == 2 || randomTrapNumber == 8) {
		br->enableTrap();
	}


	switch(to) {
	case Direction::North:
		br->setColumn(prevRoom->getColumn());
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow() - 1);

		br->setSouthRoom(prevRoom);
		prevRoom->setNorthRoom(br);
		break;
	case Direction::South:
		br->setColumn(prevRoom->getColumn());
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow() + 1);

		br->setNorthRoom(prevRoom);
		prevRoom->setSouthRoom(br);
		break;
	case Direction::West:
		br->setColumn(prevRoom->getColumn() - 1);
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow());

		br->setEastRoom(prevRoom);
		prevRoom->setWestRoom(br);
		break;
	case Direction::East:
		br->setColumn(prevRoom->getColumn() + 1);
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow());

		br->setWestRoom(prevRoom);
		prevRoom->setEastRoom(br);
		break;
	}


	br->generateDoors();

	br->setEnemies(EntityFactory::createRandomEntities());
	br->setItems(ItemFactory::createRandomItems());

	br->setDescription(generateDescription(br));

	return br;
}

std::string RoomFactory::generateDescription(BaseRoom* room) {
	std::string description = "In this room, there's ";


	std::random_device dev;
	std::default_random_engine dre(dev());

	// random amount


	std::uniform_int_distribution<int> dist1(1, 5);
	int whereNumber = dist1(dre);

	std::string where = "";

	switch(whereNumber) {
	case 1: 
		where = "in the middle";
		break;
	case 2:
		where = " in the left corner";
		break;
	case 3:
		where = " in front of you";
		break;
	case 4:
		where = " in the right corner";
		break;

	}

	std::uniform_int_distribution<int> dist2(1, 5);
	int objectNumber = dist2(dre);
	std::string object = "";

	switch(objectNumber) {
	case 1:
		object = "a table";
		break;
	case 2:
		object = "a huge pillar";
		break;
	case 3:
		object = "a drawer";
		break;
	case 4:
		object = "a giant clock";
		break;
	case 5:
		object = "a strange locked chest";
		break;
	}

	std::uniform_int_distribution<int> dist3(1, 5);
	int additiveNumber = dist3(dre);

	std::string additive = "";

	switch(additiveNumber) {
	case 1:
	case 2:
	case 3:
		additive = ".";
		break;
	case 4:
		additive = ", with a corpse next to it";
		break;
	case 5:
		additive = ", with pools of blood on the floor";
	}

	description.append(object + " " + where + additive);

	return description;
}

void RoomFactory::fixDoors(BaseRoom* newRoom) {
	if (newRoom != nullptr) {
		fixEastDoor(newRoom);
		fixWestDoor(newRoom);
		fixNorthDoor(newRoom);
		fixSouthDoor(newRoom);
	}
}

StartRoom* RoomFactory::createStartRoom(BaseRoom* prevRoom) {
	int level = 0;
	int column = 0;
	int row = 0;

	if (prevRoom == nullptr) {
		srand(time(NULL));

		level = 0;
		column = rand() % 10;
		row = rand() % 10;
	} else {
		level = prevRoom->getLevel() + 1;
		column = prevRoom->getColumn();
		row = prevRoom->getRow();
	}
	StartRoom* sr = new StartRoom(level, row, column);

	//Generate Doors
	sr->generateDoors();
	return sr;
}

void RoomFactory::fixNorthDoor(BaseRoom* newRoom) {
	auto levelVector = Game::Instance()->getRoomVector()->at(newRoom->getLevel());
	if (!levelVector.empty()) {
		if(newRoom->getRow() - 1 >= 0 && newRoom->getRow() - 1 < levelVector.size()) {
			auto rowVector = levelVector.at(newRoom->getRow() - 1);
			if (!rowVector.empty()) {
				BaseRoom* northRoom = rowVector.at(newRoom->getColumn());
				if (northRoom != nullptr) {
					if (newRoom->getSymbol() == "E") {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (northRoom->hasSouthDoor() || newRoom->hasNorthDoor()) {

							newRoom->enableNorthDoor();
							newRoom->setNorthRoom(northRoom);
							northRoom->setSouthRoom(newRoom);
							northRoom->enableSouthDoor();
						}
					}
				}
			}
		}
	}
}

void RoomFactory::fixSouthDoor(BaseRoom* newRoom) {
	auto levelVector = Game::Instance()->getRoomVector()->at(newRoom->getLevel());
	if (!levelVector.empty()) {
		if(newRoom->getRow() + 1 >= 0 && newRoom->getRow() + 1 < levelVector.size()) {
			auto rowVector = levelVector.at(newRoom->getRow() + 1);
			if (!rowVector.empty()) {
				BaseRoom* southRoom = rowVector.at(newRoom->getColumn());
				if (southRoom != nullptr) {
					if (newRoom->getSymbol() == "E") {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (southRoom->hasNorthDoor() || newRoom->hasSouthDoor()) {

							newRoom->enableSouthDoor();
							newRoom->setSouthRoom(southRoom);
							southRoom->setNorthRoom(newRoom);
							southRoom->enableNorthDoor();
						}
					}
				}
			}
		}
	}
}

void RoomFactory::fixEastDoor(BaseRoom* newRoom) {
	auto levelVector = Game::Instance()->getRoomVector()->at(newRoom->getLevel());
	if (!levelVector.empty()) {
		auto rowVector = levelVector.at(newRoom->getRow());
		if (!rowVector.empty()) {
			if(newRoom->getColumn() + 1 >= 0 && newRoom->getColumn() + 1 < levelVector.size()) {
				BaseRoom* eastRoom = rowVector.at(newRoom->getColumn() + 1);
				if (eastRoom != nullptr) {
					if (newRoom->getSymbol() == "E") {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (eastRoom->hasWestDoor() || newRoom->hasEastDoor()) {
							newRoom->enableEastDoor();
							newRoom->setEastRoom(eastRoom);
							eastRoom->setWestRoom(newRoom);
							eastRoom->enableWestDoor();
						}
					}
				}
			}
		}
	}
}

void RoomFactory::fixWestDoor(BaseRoom* newRoom) {
	auto levelVector = Game::Instance()->getRoomVector()->at(newRoom->getLevel());
	if (!levelVector.empty()) {
		auto rowVector = levelVector.at(newRoom->getRow());
		if (!rowVector.empty()) {
			if(newRoom->getColumn() - 1 >= 0 && newRoom->getColumn() - 1 < levelVector.size()) {
				BaseRoom* westRoom = rowVector.at(newRoom->getColumn() - 1);
				if (westRoom != nullptr) {
					if (newRoom->getSymbol() == "E") {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (westRoom->hasEastDoor() || newRoom->hasWestDoor()) {

							newRoom->enableWestDoor();
							newRoom->setWestRoom(westRoom);
							westRoom->setEastRoom(newRoom);
							westRoom->enableEastDoor();
						}
					}
				}
			}
		}
	}
}


