#include "Zombie.h"


Zombie::Zombie(void)
{
	this->setEntityType(EntityType::Zombie);
	this->setName("Zombie");
}

std::string Zombie::toString() {
	return	this->getName();
}


Zombie::~Zombie(void)
{
}
