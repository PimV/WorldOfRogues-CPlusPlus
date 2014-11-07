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

	void setDefencePoints(int defencepoints);
	int getDefencePoints();

	virtual ~BaseArmour(void);

	std::string toString();


	void setType(ArmourType armourType);
	ArmourType getType();

protected:
	ArmourType armourType;

	int defencepoints;
	int armourRating;
	int offenseRating;
};

