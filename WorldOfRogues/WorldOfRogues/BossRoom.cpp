#include "BossRoom.h"



BossRoom::BossRoom(int level, int row, int column) : BaseRoom(level,row,column)
{
	this->setSymbol("B");

}


BossRoom::~BossRoom(void)
{
}
