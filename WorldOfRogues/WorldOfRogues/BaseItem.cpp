#include "BaseItem.h"
#include <string>



BaseItem::BaseItem(void)
{
	count = 1;
}

int BaseItem::getCount() {
	return count;
}

void BaseItem::setCount(int count) {

	this->count = count;
	if (this->count < 0) {
		this->count = 0;
	}
}

void BaseItem::setLevel(int level)
{
	this->level = level;
}

int BaseItem::getLevel()
{
	return this->level;
}

BaseItem::~BaseItem(void)
{
}

std::string BaseItem::toString()
{
	return std::string(this->Name);
}
