#include "StandardRoom.h"


StandardRoom::StandardRoom(int row, int column, int level) : BaseRoom(row,column,level)
{
}

std::string StandardRoom::toString() {	
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

StandardRoom::~StandardRoom(void)
{
}
