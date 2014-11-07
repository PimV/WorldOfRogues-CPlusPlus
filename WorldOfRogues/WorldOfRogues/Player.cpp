#include "Player.h"
#include "Player_Inventory.h"
#include "Player_Equipment.h"
#include "HealthPotion.h"
#include "ExperiencePotion.h"
#include "Weapon.h"
#include "Platebody.h"
#include "HolyHandGrenade.h"
#include "Platelegs.h"
#include "Shield.h"
#include "Helmet.h"
#include "Game.h"
#include <random>
#include "BaseRoom.h"
#include "ItemFactory.h"

Player::Player(void)
{
	this->setSkillPoints(0);

	this->setEntityType(EntityType::Player);
	this->setName("Player");

	this->setInventory(new BaseInventory());
	this->setEquipment(new BaseEquipment());

	//BasePotion* xpPot = new BasePotion();
	//xpPot->setExperience(150);

	this->getInventory()->addItem(new HealthPotion());
	this->getInventory()->addItem(new HealthPotion());
	this->getInventory()->addItem(new ExperiencePotion());
	this->getInventory()->addItem(new ExperiencePotion());
	this->getInventory()->addItem(ItemFactory::createItem(WeaponType::Sword));
	this->getInventory()->addItem(new HolyHandGrenade());

	this->setMaxHitpoints(100);
	this->setHitpoints(100);
	this->setExperience(0);

	this->setMaxLevelVisited(0);

}

void Player::setSkillPoints(int skillPoints) {
	this->skillpoints = skillPoints;
}

int Player::getSkillPoints() {
	return this->skillpoints;
}

void Player::setRoom(BaseRoom* room) {
	this->setPreviousRoom(this->getRoom());
	BaseEntity::setRoom(room);
}

bool Player::rest() {
	//Resting decreases each floor. At the top floor, you can't rest.
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(this->getRoom()->getLevel(), 10);
	int attackChance = dist1(dre);
	if (attackChance == 10) {
		return false;
	}
	this->setHitpoints(this->getHitpoints() + 15);

	return true;

}

void Player::setPreviousRoom(BaseRoom* prevRoom) {
	this->prevRoom = prevRoom;
}

bool Player::flee() {
	if (this->getPreviousRoom() == nullptr) {
		for(BaseEntity* e : this->getRoom()->getEnemies()) {
			e->attack(this);
		}
		return false;
	}

	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(this->getAgility(), 10);
	int fleeChance = dist1(dre);

	if (fleeChance < 4) {
		this->setRoom(this->getPreviousRoom());
		return true;
	} else {
		for(BaseEntity* e : this->getRoom()->getEnemies()) {
			e->attack(this);
		}
		return false;
	}


}

void Player::setExperience(int experience) {
	while (experience > getXpTillNextLevel()) {
		experience = experience - this->getLevel() * 100;
		this->setLevel(this->getLevel() + 1);
		this->setExperience(experience);
		this->setMaxHitpoints(this->getMaxHitpoints() + 10);
		this->setSkillPoints(this->getSkillPoints() + 1);
		std::cout << "Congratulations! You have just levelled up to level " << this->getLevel() << ". Enter 'strength', 'agility' or 'defence' to use your newly acquired skillpoint." << std::endl;
	}
	BaseEntity::setExperience(experience);
}

BaseRoom* Player::getPreviousRoom() {
	return this->prevRoom;
}

void Player::setHitpoints(int hitpoints) {
	if (hitpoints <= 0) {
		Game::Instance()->gameOver();
	} else {
		BaseEntity::setHitpoints(hitpoints);
	}
}

void Player::setMaxLevelVisited(int maxLevelVisited) {
	if (maxLevelVisited > this->maxLevelVisited) {
		this->maxLevelVisited = maxLevelVisited;
	}
}

int Player::getMaxLevelVisited() {
	return this->maxLevelVisited;
}

std::string Player::toString() {
	std::string player_statistics = "";
	player_statistics.append("Name: \t\t\t" + this->getName() + "\n");
	player_statistics.append("Level: \t\t\t" + std::to_string(this->getLevel()) + "\n");
	player_statistics.append("Experience: \t\t" + std::to_string(this->getExperience()) + "\\" + std::to_string(this->getLevel() * 100) +  "\n");
	player_statistics.append("Hitpoints: \t\t" + std::to_string(this->getHitpoints()) + "\\" + std::to_string(this->getMaxHitpoints()) +  "\n");
	player_statistics.append("Strength: \t\t" + std::to_string(this->getAttackPoints()) + "\n");
	player_statistics.append("Defence: \t\t" + std::to_string(this->getDefencePoints()) + "\n");
	player_statistics.append("Agility: \t\t" + std::to_string(this->getAgility()) + "\n");
	player_statistics.append("Skillpoints: \t\t" + std::to_string(this->getSkillPoints()) + "\n");
	player_statistics.append("Armour rating: \t\t" + std::to_string(this->getEquipment()->getArmourRating()) + "\n");
	player_statistics.append("Offense rating: \t" + std::to_string(this->getEquipment()->getOffenseRating()) + "\n");
	player_statistics.append("\n Type 'equipment' or 'inventory' to check your equipment/inventory.\n");
	return player_statistics;
}


Player::~Player(void)
{
	//delete this->getEquipment();
	//delete this->getInventory();
}
