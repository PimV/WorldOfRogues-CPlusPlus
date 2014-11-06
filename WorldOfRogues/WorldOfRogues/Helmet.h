#pragma once
#include "baseitem.h"
#include "basearmour.h"
class Helmet :
	public BaseArmour
{
public:
	Helmet(void);

	int getArmourRating();
	void setArmourRating(int rating);

	void use(Player* player);
	//std::string toString();
	virtual ~Helmet(void);

};

