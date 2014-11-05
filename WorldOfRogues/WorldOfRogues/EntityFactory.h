#pragma once
#include "BaseRoom.h"
#include "BaseEntity.h"
#include "EntityTypes.h"

#include <vector>
#include <iostream>

class EntityFactory
{
public:
	EntityFactory();
	virtual ~EntityFactory();

	std::vector<BaseEntity*> createEntitiesForRoom(BaseRoom *br);
private:
	BaseEntity* createEntity(EntityTypes et);
};

