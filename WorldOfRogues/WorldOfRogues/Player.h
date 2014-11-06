#pragma once
#include "baseentity.h"
class Player :
	public BaseEntity
{
public:
	Player(void);

	void setMaxLevelVisited(int maxLevelVisited);
	int getMaxLevelVisited();

	std::string toString();

	virtual ~Player(void);

private:
	int maxLevelVisited;

};

