#include "BaseEntity.h"
#include "BaseRoom.h"
#include "BaseInventory.h"
#include "BaseEquipment.h"
using namespace std;


BaseEntity::BaseEntity(void)
{
	this->setInventory(new BaseInventory());
	this->setEquipment(new BaseEquipment());
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
	this->setMaxHitpoints(this->getMaxHitpoints() + (50-this->getLevel()) * this->getLevel());
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
		std::cout << "Congratulations! You have just levelled up to level " << this->getLevel() << std::endl;
	}

	this->experience = experience;
}

int BaseEntity::getAttackPoints() {
	return this->attackpoints * (2*this->getLevel());
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

