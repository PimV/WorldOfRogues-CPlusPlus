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
	void generateExperience();

	virtual void setRoom(BaseRoom* room);
	BaseRoom* getRoom();

	void setEquipment(BaseEquipment* equipment);
	BaseEquipment* getEquipment();

	void setInventory(BaseInventory* inventory);
	BaseInventory* getInventory();

	void setName(std::string name);
	std::string getName();

	int getXpTillNextLevel();

	void setMaxHitpoints(int maxHitpoints);
	int getMaxHitpoints();

	virtual void setHitpoints(int hitpoints);
	int getHitpoints();

	virtual void setExperience(int experience);
	int getExperience();

	void setLevel(int level);
	int getLevel();

	void setAgility(int agility);
	int getAgility();

	void setAttackPoints(int attackPoints);
	int getAttackPoints();


	void setDefencePoints(int defencepoints);
	int getDefencePoints();

	int attack(BaseEntity* entity);

	void setEntityType(EntityType type);
	EntityType getEntityType();

	virtual std::string toString() = 0;

	virtual ~BaseEntity(void);
private:
	std::string name;
	int level;
	int maxHitpoints;
	int hitpoints;
	int agility;
	int experience;
	int attackpoints;
	int defencepoints;
	BaseRoom* room;
	EntityType type;
	//Inventory
	BaseEquipment* equipment;
	BaseInventory* inventory;
};

