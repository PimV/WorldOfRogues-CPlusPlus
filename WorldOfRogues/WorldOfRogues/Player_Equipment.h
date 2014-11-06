#pragma once
#include "BaseEquipment.h"
class Player_Equipment :
	public BaseEquipment
{
public:


	int getArmourRating();

	Player_Equipment(void);
	virtual ~Player_Equipment(void);
};

