#include "BaseEntity.h"
#include "BaseRoom.h"
#include "BaseInventory.h"
#include "BaseEquipment.h"
#include <random>
using namespace std;


BaseEntity::BaseEntity(void)
{
	this->attackpoints = 1;
	this->agility = 1;
	this->setInventory(new BaseInventory());
	this->setEquipment(new BaseEquipment());
}

int BaseEntity::attack(BaseEntity* entity) {
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(this->getAgility(), 50);
	int hitChance = dist1(dre);
	int healthLeft = entity->getHitpoints();
	if (hitChance > 10) {
		healthLeft -= this->getAttackPoints();

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
	}
	this->hitpoints = hitpoints;
}

int BaseEntity::getExperience() {
	return this->experience;
}

void BaseEntity::setExperience(int experience) {
	//Keep levelling till experience is up
	while (experience > getXpTillNextLevel()) {
		experience = experience - this->getLevel() * 100;
		this->setLevel(this->getLevel() + 1);
		this->experience = experience;
		this->setMaxHitpoints(this->getMaxHitpoints() + 10);
		this->agility = this->getLevel();
		std::cout << "Congratulations! You have just levelled up to level " << this->getLevel() << std::endl;
	}

	this->experience = experience;
}

int BaseEntity::getAttackPoints() {
	return this->attackpoints * (2*this->getLevel()) + this->getEquipment()->getOffenseRating();
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

