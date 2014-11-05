#pragma once
#include "baseentity.h"
class Dwarf :
	public BaseEntity
{
public:
	Dwarf(void);
	std::string toString();
	virtual ~Dwarf(void);
};

