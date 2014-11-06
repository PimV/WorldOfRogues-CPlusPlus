#include "Boss.h"


Boss::Boss(void)
{
	this->setEntityType(EntityType::Boss);
	this->setName("Boss");
}

std::string Boss::toString() {
	return this->getName();
}


Boss::~Boss(void)
{
}
