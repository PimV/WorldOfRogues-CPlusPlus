#pragma once
#include "baseroom.h"
class StartRoom :
	public BaseRoom
{
public:
	StartRoom(int row, int column, int level);
	virtual ~StartRoom(void);
};

