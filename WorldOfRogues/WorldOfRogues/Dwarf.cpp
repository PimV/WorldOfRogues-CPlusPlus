#include "Dwarf.h"


Dwarf::Dwarf(void)
{
}

std::string Dwarf::toString() {
	return std::string(
		std::string("Dwarf L") +
		std::to_string(this->getLevel())
		);
}


Dwarf::~Dwarf(void)
{
}
