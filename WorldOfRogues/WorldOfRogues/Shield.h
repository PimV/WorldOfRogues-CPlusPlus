#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Shield :
	public BaseItem, public BaseArmour
{
public:
	Shield(void);
	std::string toString();
	virtual ~Shield(void);
};

