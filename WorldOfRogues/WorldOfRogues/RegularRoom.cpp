#include "RegularRoom.h"


RegularRoom::RegularRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("R");
}


RegularRoom::~RegularRoom(void)
{
}
