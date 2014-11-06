#pragma once
#include "baseentity.h"
class Rat :
	public BaseEntity
{
public:
	Rat(void);
	std::string toString();

	virtual ~Rat(void);
};

