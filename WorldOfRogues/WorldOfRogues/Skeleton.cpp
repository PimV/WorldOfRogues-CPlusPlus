#include "Skeleton.h"


Skeleton::Skeleton(void)
{
	this->setEntityType(EntityType::Skeleton);
	this->setName("Zombie");
}

std::string Skeleton::toString() {
	return this->getName();
}



Skeleton::~Skeleton(void)
{
}
