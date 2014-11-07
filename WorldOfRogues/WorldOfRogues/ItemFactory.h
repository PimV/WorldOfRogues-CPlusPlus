#pragma once
#include "BaseItem.h"
#include "ItemType.h"

#include <vector>
#include <iostream>

class ItemFactory
{
public:
	virtual ~ItemFactory();
	
	static BaseItem* createItem(WeaponType weaponType);
	static BaseItem* createItem(ArmourType armourType);
	static std::vector<BaseItem*> createRandomItems();
private:
	std::string generateName(BaseWeapon* item);
	std::string generateName(BaseArmour* item);
};

