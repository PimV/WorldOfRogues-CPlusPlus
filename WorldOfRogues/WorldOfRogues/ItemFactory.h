#pragma once
#include "BaseItem.h"

#include <vector>
#include <iostream>

class ItemFactory
{
public:
	virtual ~ItemFactory();
	
	static BaseItem* createItem(std::string item);
	static std::vector<BaseItem*> createRandomItems();
private:
};

