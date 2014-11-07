#include "Dwarf.h"


Dwarf::Dwarf(void)
{
	this->setEntityType(EntityType::Dwarf);
	this->setName("Dwarf");
	this->setMaxHitpoints(35);
	this->setHitpoints(35);

}

std::string Dwarf::toString() {
	return std::string("Dwarf");
}


Dwarf::~Dwarf(void)
{
}
