#include "BaseWeapon.h"


BaseWeapon::BaseWeapon(void) : BaseItem()
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

std::string BaseWeapon::toString()
{
	return this->getName();
}
