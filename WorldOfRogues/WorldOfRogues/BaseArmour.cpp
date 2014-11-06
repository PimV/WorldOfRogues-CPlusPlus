#include "BaseArmour.h"

BaseArmour::BaseArmour(void)
{
}


BaseArmour::~BaseArmour(void)
{
}

std::string BaseArmour::toString()
{
	return std::string(
		std::string("") +
		std::string(this->Name) +
		std::string(" ") +
		std::to_string(this->defencepoints) +
		std::string(" defence points.") 
		);
}


