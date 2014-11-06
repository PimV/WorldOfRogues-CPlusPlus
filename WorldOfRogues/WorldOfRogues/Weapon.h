#pragma once
#include "baseitem.h"
#include "baseweapon.h"
class Weapon :
	public BaseItem, public BaseWeapon
{
public:
	Weapon(void);
	virtual ~Weapon(void);

};

