#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Shield :
	public BaseItem, public BaseArmour
{
public:
	Shield(void);
	void use(Player* player);
	std::string toString();
	virtual ~Shield(void);
};

