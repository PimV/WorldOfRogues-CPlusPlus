#include "Boss.h"


Boss::Boss(void)
{
	this->setEntityType(EntityType::Boss);
	this->setName("Boss");
	this->setMaxHitpoints(200);
	this->setHitpoints(200);

}

std::string Boss::toString() {
	return this->getName();
}


Boss::~Boss(void)
{
}
