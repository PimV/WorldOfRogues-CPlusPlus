#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Platelegs :
	public BaseItem, public BaseArmour
{
public:
	Platelegs(void);
	std::string toString();
	virtual ~Platelegs(void);
};

