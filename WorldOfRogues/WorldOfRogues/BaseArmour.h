#pragma once
#include "BaseItem.h"
#include "ItemType.h"

class BaseArmour : 
	public BaseItem
{
public:
	BaseArmour(void);

	void setArmourRating(int rating);
	int getArmourRating();

	void setOffenseRating(int rating);
	int getOffenseRating();

	virtual ~BaseArmour(void);

	std::string toString();
	int defencepoints;
	int armourRating;
	int offenseRating;

	void setType(ArmourType* armourType);
	ArmourType* getType();

protected:
	ArmourType* armourType;
};

