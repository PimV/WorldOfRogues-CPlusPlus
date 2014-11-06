#include "Skeleton.h"


Skeleton::Skeleton(void)
{
	this->setEntityType(EntityType::Skeleton);
	this->setName("Zombie");
	this->setHitpoints(25);
	this->setMaxHitpoints(25);
}

std::string Skeleton::toString() {
	return this->getName();
}



Skeleton::~Skeleton(void)
{
}
