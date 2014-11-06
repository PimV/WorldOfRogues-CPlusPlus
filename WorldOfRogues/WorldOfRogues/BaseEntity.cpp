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
	return this->level;
}

int BaseEntity::getHitpoints() {
	return this->hitpoints;
}

void BaseEntity::setHitpoints(int hitpoints) {
	this->hitpoints = hitpoints;
}

int BaseEntity::getExperience() {
	return this->experience;
}

void BaseEntity::setExperience(int experience) {
	this->experience = experience;
}

int BaseEntity::getAttackPoints() {
	return this->attackpoints;
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
}

