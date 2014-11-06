#include "Helmet.h"
#include "Player_Equipment.h"
#include "Player_Inventory.h"
#include <string>

Helmet::Helmet(void)
{
}

void Helmet::use(Player* player) {
	if (player->getEquipment()->hasHelmet()) {
		player->getInventory()->addItem(player->getEquipment()->getHelmet());
	}
	player->getEquipment()->setHelmet(this);
	player->getInventory()->removeItem(this);
}

std::string Helmet::toString() {
	return std::string("helmet");
}

Helmet::~Helmet(void)
{
}
