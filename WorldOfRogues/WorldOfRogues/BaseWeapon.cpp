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

void BaseWeapon::setType(WeaponType* weaponType)
{
	this->weaponType = weaponType;
}

WeaponType* BaseWeapon::getType()
{
	return this->weaponType;
}

std::string BaseWeapon::toString()
{
	return std::string(
		std::string("") +
		std::string(this->Name) +
		std::string(" (Att. ") +
		std::to_string(this->attackpoints) +
		std::string(")")
		);
}
