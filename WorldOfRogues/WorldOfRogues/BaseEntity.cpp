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

void BaseEntity::setLevel(int level)
{
	this->level = level;
}

int BaseEntity::getLevel()
{
	return this->level;
}

BaseEntity::~BaseEntity(void)
{
}

