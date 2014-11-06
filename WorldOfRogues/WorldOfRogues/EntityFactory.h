#pragma once
#include "BaseRoom.h"
#include "BaseEntity.h"
#include "EntityType.h"

#include <vector>
#include <iostream>

class EntityFactory
{
public:
	//EntityFactory();
	virtual ~EntityFactory();
	static std::string generateName(BaseEntity* entity);
	static std::vector<BaseEntity*> createEntitiesForRoom();
	static BaseEntity* createEntity(EntityType et);
private:

};

