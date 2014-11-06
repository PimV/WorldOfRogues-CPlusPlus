#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Shield :
	public BaseArmour
{
public:
	Shield(void);
	int getArmourRating();
	void setArmourRating(int rating);
	void use(Player* player);
	//std::string toString();
	virtual ~Shield(void);

};

