#pragma once
#include "baseentity.h"
class Zombie :
	public BaseEntity
{
public:
	Zombie(void);
	std::string toString();

	virtual ~Zombie(void);
};

