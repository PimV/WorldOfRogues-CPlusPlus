#include "RoomFactory.h"
#include "Direction.h"
#include <random>
#include <iostream>

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
		br = new StandardRoom(-1,-1,-1);
		break;
	case 7: 
		br = new BossRoom(-1,-1,-1);
		break;
	case 8: 
		br = new EndRoom(-1,-1,-1);
		break;
	default:
		br = new StandardRoom(-1,-1,-1);
		break;
	}



	switch(to) {
	case Direction::North:
		br->setColumn(prevRoom->getColumn());
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow() - 1);

		br->setSouthRoom(prevRoom);
		break;
	case Direction::South:
		br->setColumn(prevRoom->getColumn());
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow() + 1);

		br->setNorthRoom(prevRoom);
		break;
	case Direction::West:
		br->setColumn(prevRoom->getColumn() - 1);
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow());

		br->setEastRoom(prevRoom);
		break;
	case Direction::East:
		br->setColumn(prevRoom->getColumn() + 1);
		br->setLevel(prevRoom->getLevel());
		br->setRow(prevRoom->getRow());

		br->setWestRoom(prevRoom);
		break;
	}

	std::cout << br->toString() << "\n";

	return br;
}
