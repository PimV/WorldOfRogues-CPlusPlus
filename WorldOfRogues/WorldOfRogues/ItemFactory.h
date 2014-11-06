#pragma once
#include "BaseItem.h"
#include "ItemType.h"

#include <vector>
#include <iostream>

class ItemFactory
{
public:
	virtual ~ItemFactory();
	
	static BaseItem* createItem(ItemType it);
	static std::vector<BaseItem*> createRandomItems();
private:
};

