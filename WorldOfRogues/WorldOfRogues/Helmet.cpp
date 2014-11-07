#include "Helmet.h"
#include "BaseInventory.h"
#include "BaseEquipment.h"
#include <string>


Helmet::Helmet(void)
{
	this->setArmourRating(5);
}

void Helmet::setArmourRating(int rating) {
	this->armourRating = rating;
}

int Helmet::getArmourRating() {
	return this->armourRating;
}

void Helmet::use(Player* player) {
	if (player->getEquipment()->hasHelmet()) {
		player->getInventory()->addItem(player->getEquipment()->getHelmet(),1);
	}
	player->getEquipment()->setHelmet(this);
	player->getInventory()->removeItem(this,1);
}

//std::string Helmet::toString() {
//	return std::string("helmet");
//}

Helmet::~Helmet(void)
{
}
