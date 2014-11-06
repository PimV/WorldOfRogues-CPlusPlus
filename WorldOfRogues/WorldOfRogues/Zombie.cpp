#include "Zombie.h"


Zombie::Zombie(void)
{
	this->setEntityType(EntityType::Zombie);
	this->setName("Zombie");
	this->setHitpoints(100);
	this->setMaxHitpoints(100);
}

std::string Zombie::toString() {
	return	this->getName();
}


Zombie::~Zombie(void)
{
}
