#include "StartRoom.h"


StartRoom::StartRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("S");
}

std::string StartRoom::toString() {
	return std::string("startroom");
	/*return std::string(
		std::string("Start Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);*/
}

StartRoom::~StartRoom(void)
{
}
