#include "BaseItem.h"


BaseItem::BaseItem(void)
{
}


BaseItem::~BaseItem(void)
{
}

std::string BaseItem::toString()
{
	return std::string(this->Name);
}
