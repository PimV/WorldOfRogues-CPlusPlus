#include "Skeleton.h"


Skeleton::Skeleton(void)
{
	this->setEntityType(EntityType::Skeleton);
	this->setName("Skeleton");
	this->setMaxHitpoints(25);
	this->setHitpoints(25);

}

std::string Skeleton::toString() {
	return this->getName();
}



Skeleton::~Skeleton(void)
{
}
