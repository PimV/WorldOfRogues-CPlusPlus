#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Platebody :
	public BaseItem, public BaseArmour
{
public:
	Platebody(void);
	int getArmourRating();
	void setArmourRating(int rating);
	void use(Player* player);
	std::string toString();
	virtual ~Platebody(void);
};

