#pragma once
#include "BaseItem.h"
#include "ItemType.h"
#include "BaseWeapon.h"
#include "BaseArmour.h"

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

	static void calculateLevel(BaseItem* item);
	static void setNameAndLevel(BaseWeapon* item);
	static void setNameAndLevel(BaseArmour* item);
};

