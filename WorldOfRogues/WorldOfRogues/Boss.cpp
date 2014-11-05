#include "Boss.h"


Boss::Boss(void)
{
}

std::string Boss::toString() {
	return std::string(
		std::string("Boss L") +
		std::to_string(this->getLevel())
		);
}


Boss::~Boss(void)
{
}
