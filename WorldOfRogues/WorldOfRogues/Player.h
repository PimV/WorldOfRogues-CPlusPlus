#pragma once
#include "baseentity.h"
class Player_Equipment;
class Player_Inventory;
class Player :
	public BaseEntity
{
public:
	Player(void);

	void setEquipment(Player_Equipment* equipment);
	Player_Equipment* getEquipment();

	void setInventory(Player_Inventory* inventory);
	Player_Inventory* getInventory();

	void setMaxLevelVisited(int maxLevelVisited);
	int getMaxLevelVisited();

	std::string toString();

	virtual ~Player(void);

private:
	int maxLevelVisited;
	Player_Equipment* equipment;
	Player_Inventory* inventory;
};

