#pragma once
#include "baseitem.h"
class HolyHandGrenade :
	public BaseItem
{
public:
	HolyHandGrenade(void);
	void use(Player* player);
	virtual ~HolyHandGrenade(void);
};

