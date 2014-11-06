#pragma once
#include "baseentity.h"
class Boss :
	public BaseEntity
{
public:
	Boss(void);
	std::string toString();
	virtual ~Boss(void);
};

