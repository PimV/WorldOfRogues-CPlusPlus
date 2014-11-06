#pragma once
#include "BaseItem.h"

class BaseArmour : 
	public BaseItem
{
public:
	BaseArmour(void);
	virtual ~BaseArmour(void);

	std::string toString();
protected:
	int defencepoints;
};

