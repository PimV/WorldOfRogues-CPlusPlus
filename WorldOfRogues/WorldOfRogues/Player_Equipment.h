#pragma once
#include "BaseInventory.h"
class Player_Equipment :
	public BaseInventory
{
public:


	void getArmourRating();

	Player_Equipment(void);
	virtual ~Player_Equipment(void);
};

