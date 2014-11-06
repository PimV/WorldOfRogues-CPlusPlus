#pragma once
class BaseWeapon
{
public:
	BaseWeapon(void);
	void setOffenseRating(int rating);
	int getOffenseRating();
	virtual ~BaseWeapon(void);
protected:
	int attackpoints;
	int offenseRating;
};

