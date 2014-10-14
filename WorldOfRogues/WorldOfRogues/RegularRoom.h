#pragma once
#include "baseroom.h"
class RegularRoom :
	public BaseRoom
{
public:
	RegularRoom(int row, int column, int level);
	std::string toString();
	virtual ~RegularRoom(void);
};

