#include "Zombie.h"


Zombie::Zombie(void)
{
}

std::string Zombie::toString() {
	return std::string(
		std::string("Zombie L") +
		std::to_string(this->getLevel())
		);
}


Zombie::~Zombie(void)
{
}
