#include "Dwarf.h"


Dwarf::Dwarf(void)
{
	this->setEntityType(EntityType::Dwarf);
	this->setName("Dwarf");
}

std::string Dwarf::toString() {
	return std::string("Dwarf");
}


Dwarf::~Dwarf(void)
{
}
