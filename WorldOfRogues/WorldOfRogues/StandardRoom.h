#pragma once
#include "baseroom.h"
class StandardRoom :
	public BaseRoom
{
public:
	StandardRoom(int row, int column, int level);
	std::string toString();
	virtual ~StandardRoom(void);
};

