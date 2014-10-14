#include "EndRoom.h"


EndRoom::EndRoom(int row, int column, int level) : BaseRoom(row,column,level)
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
