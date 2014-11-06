#pragma once
#include "BaseItem.h"

#include <vector>
#include <iostream>

class ItemFactory
{
public:
	ItemFactory();
	virtual ~ItemFactory();

	std::vector<BaseItem*> createRandomItems();
private:
	BaseItem* createItem(std::string *item);
};

