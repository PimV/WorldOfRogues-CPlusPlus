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

void BaseWeapon::setType(WeaponType weaponType)
{
	this->weaponType = weaponType;
}

void BaseWeapon::setAttackPoints(int attackpoints)
{
	this->attackpoints = attackpoints;
}

int BaseWeapon::getAttackPoints()
{
	return this->attackpoints;
}

WeaponType BaseWeapon::getType()
{
	return this->weaponType;
}

std::string BaseWeapon::toString()
{
	return this->getName();
}
