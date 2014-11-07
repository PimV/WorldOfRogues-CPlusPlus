#pragma once
#include "baseitem.h"
#include "baseweapon.h"
class Weapon :
	public BaseWeapon
{
public:
	Weapon(void);
	void use(Player* player);
	virtual ~Weapon(void);

};

