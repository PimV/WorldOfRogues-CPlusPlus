#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Platebody :
	public BaseItem, public BaseArmour
{
public:
	Platebody(void);
	void use(Player* player);
	std::string toString();
	virtual ~Platebody(void);
};

