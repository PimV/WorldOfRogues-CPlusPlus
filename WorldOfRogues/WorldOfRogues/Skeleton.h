#pragma once
#include "baseentity.h"
class Skeleton :
	public BaseEntity
{
public:
	Skeleton(void);
	std::string toString();

	virtual ~Skeleton(void);
};

