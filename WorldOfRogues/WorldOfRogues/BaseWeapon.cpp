#include "BaseWeapon.h"


BaseWeapon::BaseWeapon(void)
{
}

void BaseWeapon::setOffenseRating(int rating) {
	this->offenseRating = rating;
}

int BaseWeapon::getOffenseRating() {
	return this->offenseRating;
}

BaseWeapon::~BaseWeapon(void)
{
}
