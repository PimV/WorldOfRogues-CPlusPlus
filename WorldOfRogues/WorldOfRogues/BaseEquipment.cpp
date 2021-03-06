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
		helmetString.append(" (DEF: " + std::to_string(this->getHelmet()->getArmourRating()));
		helmetString.append(", OFF: " + std::to_string(this->getHelmet()->getOffenseRating())+ ")");
	}

	std::string platebodyString = "none";
	if (this->getPlatebody() != nullptr) {
		platebodyString = this->getPlatebody()->toString();
		platebodyString.append(" (DEF: " + std::to_string(this->getPlatebody()->getArmourRating()));
		platebodyString.append(", OFF: " + std::to_string(this->getPlatebody()->getOffenseRating())+ ")");
	}
	std::string platelegsString = "none";
	if (this->getPlatelegs() != nullptr) {
		platelegsString = this->getPlatelegs()->toString();
		platelegsString.append(" (DEF: " + std::to_string(this->getPlatelegs()->getArmourRating()));
		platelegsString.append(", OFF: " + std::to_string(this->getPlatelegs()->getOffenseRating())+ ")");
	}
	std::string shieldString = "none";
	if (this->getShield() != nullptr) {
		shieldString = this->getShield()->toString();
		shieldString.append(" (DEF: " + std::to_string(this->getShield()->getArmourRating()));
		shieldString.append(", OFF: " + std::to_string(this->getShield()->getOffenseRating()) + ")");
	}
	std::string weaponString = "none";
	if (this->getWeapon() != nullptr) {
		weaponString = this->getWeapon()->toString();
		weaponString.append(" (OFF: " + std::to_string(this->getWeapon()->getOffenseRating())+ ")");
	}
	std::string equipment ="";
	equipment.append("Helmet: " + helmetString + "\n");
	equipment.append("Platebody: " + platebodyString + "\n");
	equipment.append("Platelegs: " + platelegsString + "\n");
	equipment.append("Shield: " + shieldString + "\n");
	equipment.append("Weapon: " + weaponString + "\n");
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
	delete this->weapon;
	delete this->helmet;
	delete this->platebody;
	delete this->platelegs;
	delete this->shield;
}
