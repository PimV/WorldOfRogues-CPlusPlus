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
	if (player->getEquipment()->hasPlatebody()) {
		player->getInventory()->addItem(player->getEquipment()->getPlatebody(),1);
	}
	player->getEquipment()->setPlatebody(this);
	player->getInventory()->removeItem(this,1);
}

std::string Platebody::toString() {
	return std::string("platebody");
}

Platebody::~Platebody(void)
{
}
