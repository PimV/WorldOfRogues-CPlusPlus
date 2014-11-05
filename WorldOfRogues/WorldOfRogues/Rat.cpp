#include "Rat.h"


Rat::Rat(void)
{
}

std::string Rat::toString() {
	return std::string(
		std::string("Rat L") +
		std::to_string(this->getLevel())
		);
}


Rat::~Rat(void)
{
}
