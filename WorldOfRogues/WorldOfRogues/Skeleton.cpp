#include "Skeleton.h"


Skeleton::Skeleton(void)
{
}

std::string Skeleton::toString() {
	return std::string(
		std::string("Skeleton L") +
		std::to_string(this->getLevel())
		);
}



Skeleton::~Skeleton(void)
{
}
