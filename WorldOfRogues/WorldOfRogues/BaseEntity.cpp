#include "BaseEntity.h"
#include "BaseRoom.h"
using namespace std;


BaseEntity::BaseEntity(void)
{
}

void BaseEntity::setRoom(BaseRoom* room) {
	this->room = room;
}

BaseRoom* BaseEntity::getRoom() {
	return this->room;
}

BaseEntity::~BaseEntity(void)
{
}

