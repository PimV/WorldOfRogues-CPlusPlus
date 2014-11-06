#pragma once
#include "baseroom.h"
class EndRoom :
	public BaseRoom
{
public:
	EndRoom(int row, int column, int level);
	void generateDoors() override;
	virtual ~EndRoom(void);
};

