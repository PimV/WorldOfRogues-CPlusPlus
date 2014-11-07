#pragma once
#include "BaseItem.h"
#include "ItemType.h"

class BaseWeapon :
	public BaseItem
{
public:
	BaseWeapon(void);
	void setOffenseRating(int rating);
	int getOffenseRating();
	virtual ~BaseWeapon(void);

	std::string toString();
	int attackpoints;
	int offenseRating;

	void setType(WeaponType* weaponType);
	WeaponType* getType();

protected:
	WeaponType* weaponType;
};

