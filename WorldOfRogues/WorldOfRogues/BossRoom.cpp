#include "BossRoom.h"



BossRoom::BossRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("B");

}

std::string BossRoom::toString() {
	return std::string(
		std::string("Boss Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);
}

BossRoom::~BossRoom(void)
{
}
