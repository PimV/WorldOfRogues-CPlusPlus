#include "BaseEquipment.h"
#include "Helmet.h"
#include "Platebody.h"
#include "Platelegs.h"
#include "Shield.h"
#include "Weapon.h"
#include <string>

BaseEquipment::BaseEquipment(void)
{
}

void BaseEquipment::setHelmet(Helmet* helmet) {
	this->helmet = helmet;
}

void BaseEquipment::setPlatebody(Platebody* platebody) {
	this->platebody = platebody;
}

void BaseEquipment::setPlatelegs(Platelegs* platelegs) {
	this->platelegs = platelegs;
}

void BaseEquipment::setShield(Shield* shield) {
	this->shield = shield;
}

void BaseEquipment::setWeapon(Weapon* weapon) {
	this->weapon = weapon;
}

Helmet* BaseEquipment::getHelmet() {
	return this->helmet;
}

Platebody* BaseEquipment::getPlatebody() {
	return this->platebody;
}

Platelegs* BaseEquipment::getPlatelegs() {
	return this->platelegs;
}

Shield* BaseEquipment::getShield() {
	return this->shield;
}

Weapon* BaseEquipment::getWeapon() {
	return this->weapon;
}

std::string BaseEquipment::toString() {
	std::string equipment = "\t\t\t";

	return equipment;
}

BaseEquipment::~BaseEquipment(void)
{
}