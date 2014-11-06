#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Platelegs :
	public BaseItem, public BaseArmour
{
public:
	Platelegs(void);
	int getArmourRating();
	void setArmourRating(int rating);
	void use(Player* player);
	std::string toString();
	virtual ~Platelegs(void);
};

