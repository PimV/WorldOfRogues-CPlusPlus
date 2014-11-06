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
	std::string helmetString = "none";
	if (this->getHelmet() != nullptr) {
		helmetString = this->getHelmet()->toString();
	}

	std::string platebodyString = "none";
	if (this->getPlatebody() != nullptr) {
		platebodyString = this->getPlatebody()->toString();
	}
	std::string platelegsString = "none";
	if (this->getPlatelegs() != nullptr) {
		platelegsString = this->getPlatelegs()->toString();
	}
	std::string shieldString = "none";
	if (this->getShield() != nullptr) {
		shieldString = this->getShield()->toString();
	}
	std::string weaponString = "none";
	if (this->getWeapon() != nullptr) {
		weaponString = this->getWeapon()->toString();
	}
	std::string equipment ="";
	equipment.append("\t" + helmetString + "\t\t\n");
	equipment.append(weaponString + "\t" + platebodyString + "\t" + shieldString + "\n");
	equipment.append("\t" + platelegsString + "\t\t\n");
	return equipment.c_str();
}

BaseEquipment::~BaseEquipment(void)
{
}
