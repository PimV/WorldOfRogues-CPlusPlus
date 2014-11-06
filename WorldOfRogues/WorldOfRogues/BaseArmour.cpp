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


BaseArmour::~BaseArmour(void)
{
}

std::string BaseArmour::toString()
{
	return this->getName();
}


