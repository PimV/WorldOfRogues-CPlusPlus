#include "BaseEntity.h"
#include "BaseRoom.h"
#include "BaseInventory.h"
#include "BaseEquipment.h"
using namespace std;


BaseEntity::BaseEntity(void)
{
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

BaseEntity::~BaseEntity(void)
{
}

