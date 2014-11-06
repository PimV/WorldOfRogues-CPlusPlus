#include "EndRoom.h"


EndRoom::EndRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("E");

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
