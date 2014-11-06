#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Helmet :
	public BaseItem, public BaseArmour
{
public:
	Helmet(void);
	virtual ~Helmet(void);

};

