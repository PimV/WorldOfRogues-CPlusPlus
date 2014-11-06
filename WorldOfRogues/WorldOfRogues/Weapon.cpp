#include "Weapon.h"
#include "Player_Equipment.h"
#include "Player_Inventory.h"
#include <string>

Weapon::Weapon(void)
{
}

void Weapon::use(Player* player) {
	if (player->getEquipment()->hasWeapon()) {
		player->getInventory()->addItem(player->getEquipment()->getWeapon());
	}
	player->getEquipment()->setWeapon(this);
	player->getInventory()->removeItem(this);
}

std::string Weapon::toString() {
	return std::string("weapon");
}


Weapon::~Weapon(void)
{
}
