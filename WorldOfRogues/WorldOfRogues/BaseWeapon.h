#pragma once
#include "BaseItem.h"

class BaseWeapon :
	public BaseItem
{
public:
	BaseWeapon(void);
	virtual ~BaseWeapon(void);

	std::string toString();
	int attackpoints;

protected:
};

