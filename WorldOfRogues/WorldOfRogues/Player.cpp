#include "Player.h"
#include "Player_Inventory.h"
#include "Player_Equipment.h"
#include "Weapon.h"
#include "Platebody.h"
#include "Platelegs.h"
#include "Shield.h"
#include "Helmet.h"

Player::Player(void)
{
	this->setEntityType(EntityType::Player);
	this->setName("Player");

	this->setInventory(new Player_Inventory());
	this->setEquipment(new Player_Equipment());

	this->getInventory()->addItem(new Weapon());
	this->getInventory()->addItem(new Platebody());
	this->getInventory()->addItem(new Platelegs());
	this->getInventory()->addItem(new Shield());
	this->getInventory()->addItem(new Helmet());

	this->setHitpoints(100);
	this->setExperience(0);

}



void Player::setMaxLevelVisited(int maxLevelVisited) {
	if (maxLevelVisited > this->maxLevelVisited) {
		this->maxLevelVisited = maxLevelVisited;
	}
}

int Player::getMaxLevelVisited() {
	return this->maxLevelVisited;
}

std::string Player::toString() {
	std::string player_statistics = "";
	player_statistics.append("Level: \t\t\t" + std::to_string(this->getLevel()) + "\n");
	player_statistics.append("Experience: \t\t" + std::to_string(this->getExperience()) + "\n");
	player_statistics.append("Hitpoints: \t\t" + std::to_string(this->getHitpoints()) + "\n");
	player_statistics.append("Armour rating: \t\t" + std::to_string(this->getEquipment()->getArmourRating()) + "\n");
	player_statistics.append("Offense rating: \t" + std::to_string(this->getEquipment()->getOffenseRating()) + "\n");

	player_statistics.append("\n Type 'equipment' or 'inventory' to check your equipment/inventory.\n");
	return player_statistics;
}


Player::~Player(void)
{
	delete this->getEquipment();
	delete this->getInventory();
}
