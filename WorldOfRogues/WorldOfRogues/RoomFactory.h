#pragma once
#include "BaseRoom.h"
#include "RegularRoom.h"
#include "EndRoom.h"
#include "BossRoom.h"
#include "StartRoom.h"

enum class Direction;
class RoomFactory
{
public:
	BaseRoom* createRoom(BaseRoom* prevRoom, Direction to);
	StartRoom* createStartRoom(BaseRoom* prevRoom);
};

