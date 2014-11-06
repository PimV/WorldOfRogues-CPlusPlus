#pragma once
#include "BaseEntity.h"
#include "EntityType.h"

#include <vector>
#include <iostream>

class EntityFactory
{
public:
	virtual ~EntityFactory();
	
	static BaseEntity* createEntity(EntityType et);
	static std::vector<BaseEntity*> createRandomEntities();
private:
};

