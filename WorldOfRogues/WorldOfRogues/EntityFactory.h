#pragma once
#include "BaseRoom.h"
#include "BaseEntity.h"
#include "EntityType.h"

#include <vector>
#include <iostream>

class EntityFactory
{
public:
	EntityFactory();
	virtual ~EntityFactory();

	std::vector<BaseEntity*> createEntitiesForRoom();
private:
	BaseEntity* createEntity(EntityType et);
};

