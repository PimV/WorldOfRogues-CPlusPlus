#include "BaseEntity.h"
#include "BaseRoom.h"
#include "BaseInventory.h"
#include "BaseEquipment.h"
#include <random>
using namespace std;


BaseEntity::BaseEntity(void)
{
	this->attackpoints = 3;
	this->defencepoints = 1;
	this->setAgility(1);
	this->setInventory(new BaseInventory());
	this->setEquipment(new BaseEquipment());

	this->generateExperience();
}

void BaseEntity::generateExperience() {
	int experience = 0;

	experience += 15*this->getLevel();
	experience += this->getAttackPoints();
	experience += this->getHitpoints() / 10;

	this->setExperience(experience);
}

int BaseEntity::attack(BaseEntity* entity) {
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(this->getAgility(), 50);
	int hitChance = dist1(dre);
	int healthLeft = entity->getHitpoints();
	if (hitChance > 10) {
		healthLeft -= (this->getAttackPoints() + this->getEquipment()->getOffenseRating());
		healthLeft += (entity->getEquipment()->getArmourRating() / 2) + this->getDefencePoints();
		if (healthLeft >= entity->getHitpoints()) {
			healthLeft = entity->getHitpoints();
		} 
		entity->setHitpoints(healthLeft);


	}

	if (entity->getHitpoints() <= 0) {
		this->setExperience(this->getExperience() + entity->getExperience());

		for(auto it = entity->getInventory()->getItems()->begin(); it != entity->getInventory()->getItems()->end(); ++it) {
			this->getInventory()->addItem(it->second);
		}
	}
	return healthLeft;
}

void BaseEntity::setAgility(int agility) {
	this->agility = agility;
}

int BaseEntity::getAgility() {
	return this->agility;
}

void BaseEntity::setRoom(BaseRoom* room) {

	room->trapPlayer(this);

	this->room = room;
}

BaseRoom* BaseEntity::getRoom() {
	return this->room;
}

void BaseEntity::setInventory(BaseInventory* inventory) {
	this->inventory = inventory;
}

BaseInventory* BaseEntity::getInventory() {
	return this->inventory;
}

void BaseEntity::setEquipment(BaseEquipment* equipment) {
	this->equipment = equipment;
}

BaseEquipment* BaseEntity::getEquipment() {
	return this->equipment;
}

void BaseEntity::setLevel(int level)
{
	this->level = level;
}

int BaseEntity::getLevel()
{
	if (this->level < 1) {
		this->level = 1;
	}
	return this->level;
}

int BaseEntity::getXpTillNextLevel() {
	return this->getLevel() * 100 - this->getExperience();
}

int BaseEntity::getMaxHitpoints() {
	return this->maxHitpoints;
}

void BaseEntity::setMaxHitpoints(int maxHitpoints) {
	this->maxHitpoints = maxHitpoints;
}

int BaseEntity::getHitpoints() {
	return this->hitpoints;
}

void BaseEntity::setHitpoints(int hitpoints) {
	if (hitpoints > this->getMaxHitpoints()) {
		this->hitpoints = this->getMaxHitpoints();
	} else {
		this->hitpoints = hitpoints;
	}
}

int BaseEntity::getExperience() {
	return this->experience;
}

void BaseEntity::setExperience(int experience) {
	this->experience = experience;
}

int BaseEntity::getDefencePoints() {
	return this->defencepoints;
}

void BaseEntity::setDefencePoints(int defencepoints) {
	this->defencepoints = defencepoints;
}

int BaseEntity::getAttackPoints() {
	return this->attackpoints ;
}

void BaseEntity::setAttackPoints(int attackpoints) {
	this->attackpoints = attackpoints;
}

EntityType BaseEntity::getEntityType() {
	return this->type;
}

void BaseEntity::setEntityType(EntityType type) {
	this->type = type;
}

std::string BaseEntity::getName() {
	return this->name;
}

void BaseEntity::setName(std::string name) {
	this->name = name;
}


BaseEntity::~BaseEntity(void)
{
	delete this->room;

	delete this->equipment;
	this->equipment = nullptr;


	delete this->inventory;
	this->inventory = nullptr;
}

