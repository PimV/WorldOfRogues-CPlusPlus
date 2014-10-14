#pragma once
#include "BaseRoom.h"
#include "StandardRoom.h"
#include "EndRoom.h"
#include "BossRoom.h"
#include "StartRoom.h"

enum class Direction;
class RoomFactory
{
public:
	BaseRoom* createRoom(BaseRoom* prevRoom, Direction from);
};

