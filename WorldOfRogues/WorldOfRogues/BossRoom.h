#pragma once
#include "baseroom.h"
class BossRoom :
	public BaseRoom
{
public:
	BossRoom(int row, int column, int level);
	std::string toString();
	virtual ~BossRoom(void);
};

