#pragma once
#include "ItemType.h"

#include <vector>
#include <iostream>

class ItemFactory
{
public:
	ItemFactory();
	virtual ~ItemFactory();

	//std::vector<BaseEntity*> createEntitiesForRoom();
private:
	//BaseEntity* createEntity(EntityType et);
};

