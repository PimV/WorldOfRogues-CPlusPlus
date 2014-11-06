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

	int randomRoomNumber = rand() % 20 + 1;
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
		/*	br = new RegularRoom(-1, -1, -1);
		break;*/
	case 19: 
		/*	br = new BossRoom(-1,-1,-1);
		break;*/
	case 20: 
		br = new EndRoom(-1,-1,-1);
		break;
	default:
		br = new RegularRoom(-1, -1, -1);
		break;
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

	std::cout << "Items in room:" << std::endl;
	for (BaseItem* item : br->getItems())
	{
		std::cout << "\t" << item->toString() << std::endl;
	}

	return br;
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
					if (newRoom->toString() == std::string("endroom")) {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (northRoom->hasSouthDoor() || newRoom->hasNorthDoor()) {
							std::cout << "Linking north - south" << std::endl;
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
					if (newRoom->toString() == std::string("endroom")) {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (southRoom->hasNorthDoor() || newRoom->hasSouthDoor()) {
							std::cout << "Linking south - north" << std::endl;
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
					if (newRoom->toString() == std::string("endroom")) {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (eastRoom->hasWestDoor() || newRoom->hasEastDoor()) {
							std::cout << "Linking east - west" << std::endl;
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
					if (newRoom->toString() == std::string("endroom")) {
						newRoom = new BaseRoom(newRoom->getRow(), newRoom->getColumn(), newRoom->getLevel());
					} else {
						if (westRoom->hasEastDoor() || newRoom->hasWestDoor()) {
							std::cout << "Linking west - east" << std::endl;
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


