#include "Rat.h"


Rat::Rat(void)
{
	this->setEntityType(EntityType::Rat);
	this->setName("Rat");
	this->setMaxHitpoints(10);
	this->setHitpoints(10);

}

std::string Rat::toString() {
	return this->getName();
}


Rat::~Rat(void)
{
}
