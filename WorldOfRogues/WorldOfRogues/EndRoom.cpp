#include "EndRoom.h"


EndRoom::EndRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("E");

}

std::string EndRoom::toString() {
	return std::string("endroom");
	/*return std::string(
		std::string("End Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);*/
}

void EndRoom::generateDoors() {
	if (getNorthRoom() != nullptr) {
		getNorthRoom()->enableSouthDoor();
		enableNorthDoor();
	}

	if (getSouthRoom() != nullptr) {
		getSouthRoom()->enableNorthDoor();
		enableSouthDoor();
	}

	if (getWestRoom() != nullptr) {
		getWestRoom()->enableEastDoor();
		enableWestDoor();
	}

	if (getEastRoom() != nullptr) {
		getEastRoom()->enableWestDoor();
		enableEastDoor();
	}
}

EndRoom::~EndRoom(void)
{
}
