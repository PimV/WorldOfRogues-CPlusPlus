#include "BaseArmour.h"

BaseArmour::BaseArmour(void)
{
}

void BaseArmour::setArmourRating(int rating) {
	this->armourRating = rating;
}

int BaseArmour::getArmourRating() {
	return this->armourRating;
}
void BaseArmour::setOffenseRating(int rating) {
	this->offenseRating = rating;
}

int BaseArmour::getOffenseRating() {
	return this->offenseRating;
}

void BaseArmour::setDefencePoints(int defencepoints)
{
	this->defencepoints = defencepoints;
}

int BaseArmour::getDefencePoints()
{
	return this->defencepoints;
}

void BaseArmour::setType(ArmourType armourType)
{
	this->armourType = armourType;
}

ArmourType BaseArmour::getType()
{
	return this->armourType;
}

BaseArmour::~BaseArmour(void)
{
}

std::string BaseArmour::toString()
{
	return this->getName();
}


