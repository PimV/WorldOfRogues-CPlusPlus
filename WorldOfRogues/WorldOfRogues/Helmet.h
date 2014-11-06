#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Helmet :
	public BaseItem, public BaseArmour
{
public:
	Helmet(void);
	void use(Player* player);
	std::string toString();
	virtual ~Helmet(void);
};

