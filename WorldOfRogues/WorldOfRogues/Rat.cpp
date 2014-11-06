#include "Rat.h"


Rat::Rat(void)
{
	this->setEntityType(EntityType::Rat);
	this->setName("Rat");
	this->setHitpoints(10);
	this->setMaxHitpoints(10);
}

std::string Rat::toString() {
	return this->getName();
}


Rat::~Rat(void)
{
}
