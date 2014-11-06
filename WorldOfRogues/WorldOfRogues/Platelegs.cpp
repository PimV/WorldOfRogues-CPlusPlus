#include "Platelegs.h"
#include <string>
#include "BaseInventory.h"
#include "BaseEquipment.h"

Platelegs::Platelegs(void)
{
}

void Platelegs::setArmourRating(int rating) {
	this->armourRating = rating;
}

int Platelegs::getArmourRating() {
	return this->armourRating;
}

void Platelegs::use(Player* player) {
	if (player->getEquipment()->hasPlatelegs()) {
		player->getInventory()->addItem(player->getEquipment()->getPlatelegs(),1);
	}
	player->getEquipment()->setPlatelegs(this);
	player->getInventory()->removeItem(this,1);
}

//std::string Platelegs::toString() {
//	return std::string("platelegs");
//}

Platelegs::~Platelegs(void)
{
}
