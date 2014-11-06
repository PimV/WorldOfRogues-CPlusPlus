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

std::string BaseEquipment::hasItem(std::string itemString) {
	if(this->hasWeapon() && itemString == this->weapon->toString()) {
		return "weapon";
	} else if (this->hasShield() && itemString == this->shield->toString()) {
		return "shield";
	} else if (this->hasHelmet() && itemString == this->helmet->toString()) {
		return "helmet";
	} else if (this->hasPlatelegs() && itemString == this->platelegs->toString()) {
		return "platelegs";
	} else if (this->hasPlatebody() && itemString == this->platebody->toString()) {
		return "platebody";
	} else {
		return "false";
	}
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

bool BaseEquipment::hasHelmet() {
	if (this->helmet != nullptr) {
		return true;
	}
	return false;
}

bool BaseEquipment::hasPlatebody() {
	if (this->platebody != nullptr) {
		return true;
	}
	return false;
}
bool BaseEquipment::hasPlatelegs() {
	if (this->platelegs != nullptr) {
		return true;
	}
	return false;
}
bool BaseEquipment::hasShield() {
	if (this->shield != nullptr) {
		return true;
	}
	return false;
}
bool BaseEquipment::hasWeapon() {
	if (this->weapon != nullptr) {
		return true;
	}
	return false;
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

int BaseEquipment::getArmourRating() {
	int rating = 0;
	if (this->hasShield()) {
		rating += this->getShield()->getArmourRating();
	} 
	if (this->hasHelmet()) {
		rating += this->getHelmet()->getArmourRating();
	} 
	if (this->hasPlatelegs()) {
		rating += this->getPlatelegs()->getArmourRating();
	} 
	if (this->hasPlatebody()) {
		rating += this->getPlatebody()->getArmourRating();
	}
	return rating;
}

int BaseEquipment::getOffenseRating() {
	int rating = 0;
	if (this->hasShield()) {
		rating += this->getShield()->getOffenseRating();
	} 
	if (this->hasHelmet()) {
		rating += this->getHelmet()->getOffenseRating();
	} 
	if (this->hasPlatelegs()) {
		rating += this->getPlatelegs()->getOffenseRating();
	} 
	if (this->hasPlatebody()) {
		rating += this->getPlatebody()->getOffenseRating();
	}
	if (this->hasWeapon()) {
		rating += this->getWeapon()->getOffenseRating();
	}
	return rating;
}

BaseEquipment::~BaseEquipment(void)
{
}
