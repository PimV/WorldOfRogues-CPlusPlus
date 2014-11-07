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

	void setAttackPoints(int attackpoints);
	int getAttackPoints();

	virtual ~BaseWeapon(void);

	std::string toString();


	void setType(WeaponType weaponType);
	WeaponType getType();

protected:
	WeaponType weaponType;
	int attackpoints;
	int offenseRating;
};

