#include "EndRoom.h"


EndRoom::EndRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("E");

}

std::string EndRoom::toString() {
	return std::string(
		std::string("End Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);
}

EndRoom::~EndRoom(void)
{
}
