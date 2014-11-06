#pragma once
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
	static std::vector<BaseEntity*> createRandomEntities();
	static BaseEntity* createEntity(EntityType et);
	static BaseEntity* createEntity(EntityType et, int level);
private:
};

