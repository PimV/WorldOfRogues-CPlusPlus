#pragma once
#include "baseroom.h"
class EndRoom :
	public BaseRoom
{
public:
	EndRoom(int row, int column, int level);
	std::string toString();
	void generateDoors() override;
	virtual ~EndRoom(void);
};

