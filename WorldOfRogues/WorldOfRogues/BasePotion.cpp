#include "BasePotion.h"
#include "BaseInventory.h"


BasePotion::BasePotion(void)
{
	this->setExperience(0);
	this->setHealth(0);
	this->setMana(0);
}

void BasePotion::setHealth(int health) {
	this->health = health;
}

void BasePotion::setMana(int mana) {
	this->mana = mana;
}

void BasePotion::setExperience(int experience) {
	this->experience = experience;
}

int BasePotion::getHealth() {
	return this->health;
}

int BasePotion::getExperience() {
	return this->experience;
}

int BasePotion::getMana() {
	return this->mana;
}

void BasePotion::use(Player* player) {
	player->setHitpoints(player->getHitpoints() + this->getHealth());
	player->setExperience(player->getExperience() + this->getExperience());
	//player->setHitpoints(player->getMana() + this->getMana());
	player->getInventory()->removeItem(this,1);
}




BasePotion::~BasePotion(void)
{
}
