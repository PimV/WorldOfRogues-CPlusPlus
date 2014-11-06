#include "Shield.h"
#include "Player_Equipment.h"
#include "Player_Inventory.h"
#include <string>

Shield::Shield(void)
{
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
