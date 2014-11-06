#pragma once
#include "baseitem.h"
#include "baseweapon.h"
class Weapon :
	public BaseItem, public BaseWeapon
{
public:
	Weapon(void);
	void use(Player* player);
	std::string toString();
	virtual ~Weapon(void);
};

