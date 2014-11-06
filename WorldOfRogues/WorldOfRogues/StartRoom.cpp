#include "StartRoom.h"


StartRoom::StartRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("S");
}


StartRoom::~StartRoom(void)
{
}
