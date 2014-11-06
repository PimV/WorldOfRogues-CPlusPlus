#pragma once
#include <string>
#include <map>
#include "BaseItem.h"
#include "BaseEquipment.h"
class BaseInventory
{
public:
	BaseInventory(void);
	void addItem(BaseItem* item, int amount = -1);
	void removeItem(BaseItem* item, int amount = -1);
	BaseItem* getItem(std::string itemString);
	bool hasItem(std::string itemString);
	std::string toString();
	~BaseInventory(void);
private:
	std::map<std::string, BaseItem*> items;
};

