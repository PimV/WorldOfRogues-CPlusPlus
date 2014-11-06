#pragma once
#include "baseroom.h"
class BossRoom :
	public BaseRoom
{
public:
	BossRoom(int row, int column, int level);
	virtual ~BossRoom(void);
};

