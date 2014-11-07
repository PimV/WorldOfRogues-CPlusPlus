#pragma once
#include "Player.h"
#include <string>
class BaseInventory;
class BaseEquipment;
class BaseItem
{
public:
	BaseItem(void);

	int getCount();
	void setCount(int count);

	//virtual std::string toString() = 0;
	virtual void use(Player* player) = 0;
	virtual ~BaseItem(void);

	void setName(std::string name);
	std::string getName();


	virtual std::string toString();
	std::string name;
	int count;

protected:
};

