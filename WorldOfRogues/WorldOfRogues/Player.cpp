#include "Player.h"
#include "Player_Inventory.h"
#include "Player_Equipment.h"

Player::Player(void)
{
	this->inventory = new Player_Inventory();
	this->equipment = new Player_Equipment();
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
	player_statistics.append("Armour rating: \t\t" + std::to_string(this->getEquipment()->getArmourRating()) + "\n");
	return player_statistics;
}


Player::~Player(void)
{
	delete this->inventory;
	delete this->equipment;
}
