#include "Platebody.h"
#include <string>
#include "BaseInventory.h"
#include "BaseEquipment.h"
#include "BaseArmour.h"

Platebody::Platebody(void)
{
}

void Platebody::setArmourRating(int rating) {
	this->armourRating = rating;
}

int Platebody::getArmourRating() {
	return this->armourRating;
}

void Platebody::use(Player* player) {

}

std::string Platebody::toString() {
	return std::string("platebody");
}

Platebody::~Platebody(void)
{
}
