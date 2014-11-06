#include "Weapon.h"
#include <string>
#include "BaseInventory.h"
#include "BaseEquipment.h"

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
