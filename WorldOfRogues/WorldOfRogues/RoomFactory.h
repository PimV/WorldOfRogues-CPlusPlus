#pragma once
#include "BaseRoom.h"
#include "RegularRoom.h"
#include "EndRoom.h"
#include "BossRoom.h"
#include "StartRoom.h"
#include <vector>

enum class Direction;
class RoomFactory
{
public:
	RoomFactory();
	std::string generateDescription(BaseRoom* room);
	BaseRoom* createRoom(BaseRoom* prevRoom, Direction to);
	StartRoom* createStartRoom(BaseRoom* prevRoom);
	void fixDoors(BaseRoom* newRoom);

	void fixNorthDoor(BaseRoom* newRoom);
	void fixSouthDoor(BaseRoom* newRoom);
	void fixEastDoor(BaseRoom* newRoom);
	void fixWestDoor(BaseRoom* newRoom);

	virtual ~RoomFactory();
private:
};

