#include "Shield.h"
#include <string>
#include "BaseInventory.h"
#include "BaseEquipment.h"

Shield::Shield(void)
{
}

void Shield::setArmourRating(int rating) {
	this->armourRating = rating;
}

int Shield::getArmourRating() {
	return this->armourRating;
}

void Shield::use(Player* player) {
	if (player->getEquipment()->hasShield()) {
		player->getInventory()->addItem(player->getEquipment()->getShield());
	}
	player->getEquipment()->setShield(this);
	player->getInventory()->removeItem(this);
}

std::string Shield::toString() {
	return std::string("shield");
}

Shield::~Shield(void)
{
}
