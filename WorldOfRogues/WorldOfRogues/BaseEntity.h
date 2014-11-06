#pragma once
#include "EntityType.h"

#include <string>

class BaseRoom;
class BaseInventory;
class BaseEquipment;
class BaseEntity
{
public:
	BaseEntity(void);
	void setRoom(BaseRoom* room);
	BaseRoom* getRoom();

	void setEquipment(BaseEquipment* equipment);
	BaseEquipment* getEquipment();

	void setInventory(BaseInventory* inventory);
	BaseInventory* getInventory();

	void setHitpoints(int hitpoints);
	int getHitpoints();

	void setLevel(int level);
	int getLevel();

	virtual std::string toString() = 0;

	virtual ~BaseEntity(void);
protected:
	std::string Name;
	int level;
	int hitpoints;
	int attackpoints;
	BaseRoom* room;
	//Inventory
	BaseEquipment* equipment;
	BaseInventory* inventory;

private:
};

