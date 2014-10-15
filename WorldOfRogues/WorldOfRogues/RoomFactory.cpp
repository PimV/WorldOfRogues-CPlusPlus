#include "RoomFactory.h"
#include "Direction.h"
#include <random>
#include <iostream>
#include <time.h>
RoomFactory::RoomFactory(void)
{
}
RoomFactory::~RoomFactory(void)
{
}

BaseRoom* RoomFactory::createRoom(BaseRoom* prevRoom, Direction to) {
	BaseRoom* br;// = new BaseRoom(-1,-1,-1);

	int randomRoomNumber = rand() % 8 + 1;
	switch(randomRoomNumber) {
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
		br = new RegularRoom(-1, -1, -1);
		break;
	case 7: 
		br = new BossRoom(-1,-1,-1);
		break;
	case 8: 
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

	std::cout << prevRoom->getColumn() << " " <<prevRoom->getRow() << std::endl;

	br->generateDoors();
	return br;
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

	std::cout << sr->getColumn() << " " << sr->getRow() << std::endl;

	return sr;


}
