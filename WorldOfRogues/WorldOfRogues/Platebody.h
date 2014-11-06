#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Platebody :
	public BaseItem, public BaseArmour
{
public:
	Platebody(void);
	std::string toString();
	virtual ~Platebody(void);
};

