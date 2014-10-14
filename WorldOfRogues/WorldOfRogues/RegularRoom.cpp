#include "RegularRoom.h"


RegularRoom::RegularRoom(int row, int column, int level) : BaseRoom(row, column, level)
{
	this->setSymbol("R");
}

std::string RegularRoom::toString() {
	return std::string(
		std::string("Standard Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);
}

RegularRoom::~RegularRoom(void)
{
}
