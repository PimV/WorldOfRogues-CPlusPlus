#include "Rat.h"


Rat::Rat(void)
{
	this->setEntityType(EntityType::Rat);
	this->setName("Rat");
}

std::string Rat::toString() {
	return this->getName();
}


Rat::~Rat(void)
{
}
