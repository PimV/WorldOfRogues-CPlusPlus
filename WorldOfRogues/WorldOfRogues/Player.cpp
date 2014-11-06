#include "Player.h"
#include "Player_Inventory.h"
#include "Player_Equipment.h"

Player::Player(void)
{
	this->inventory = new Player_Inventory();
	this->equipment = new Player_Equipment();
}

void Player::setInventory(Player_Inventory* inventory) {
	this->inventory = inventory;
}

Player_Inventory* Player::getInventory() {
	return this->inventory;
}

void Player::setEquipment(Player_Equipment* equipment) {
	this->equipment = equipment;
}

Player_Equipment* Player::getEquipment() {
	return this->equipment;
}

void Player::setMaxLevelVisited(int maxLevelVisited) {
	if (maxLevelVisited > this->maxLevelVisited) {
		this->maxLevelVisited = maxLevelVisited;
	}
}

int Player::getMaxLevelVisited() {
	return this->maxLevelVisited;
}

Player::~Player(void)
{
	delete this->inventory;
	delete this->equipment;
}
