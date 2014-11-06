#pragma once
class BaseArmour
{
public:
	BaseArmour(void);

	void setArmourRating(int rating);
	int getArmourRating();

	void setOffenseRating(int rating);
	int getOffenseRating();

	virtual ~BaseArmour(void);

protected:
	int defencepoints;
	int armourRating;
	int offenseRating;
};

