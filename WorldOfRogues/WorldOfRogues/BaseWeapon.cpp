#include "BaseWeapon.h"


BaseWeapon::BaseWeapon(void) : BaseItem()
{
}


BaseWeapon::~BaseWeapon(void)
{
}

std::string BaseWeapon::toString()
{
	return std::string(
		std::string("") +
		std::string(this->Name) +
		std::string(" (Att. ") +
		std::to_string(this->attackpoints) +
		std::string(")")
		);
}
