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

void BaseItem::setName(std::string name)
{
	this->name = name;
}

std::string BaseItem::getName()
{
	return this->name;
}

BaseItem::~BaseItem(void)
{
}

std::string BaseItem::toString()
{
	return std::string(this->getName());
}
