#include "BaseRoom.h"

BaseRoom::BaseRoom(int row, int column, int level)
{
	this->row = row;
	this->column = column;
	this->level = level;
}

#pragma region Room Properties
void BaseRoom::setRow(int row) {
	this->row = row;
}
void BaseRoom::setColumn(int column) {
	this->column = column;
}
void BaseRoom::setLevel(int level) {
	this->level = level;
}
int BaseRoom::getRow() {
	return this->row;
}
int BaseRoom::getColumn() {
	return this->column;
}
int BaseRoom::getLevel() {
	return this->level;
}
#pragma endregion
#pragma region Rooms
void BaseRoom::setNorthRoom(BaseRoom* room) {
	this->northRoom = room;
}
void BaseRoom::setSouthRoom(BaseRoom* room) {
	this->southRoom = room;
}
void BaseRoom::setEastRoom(BaseRoom* room) {
	this->eastRoom = room;
}
void BaseRoom::setWestRoom(BaseRoom* room) {
	this->westRoom = room;
}
BaseRoom* BaseRoom::getNorthRoom() {
	return this->northRoom;
}
BaseRoom* BaseRoom::getSouthRoom() {
	return this->southRoom;
}
BaseRoom* BaseRoom::getEastRoom() {
	return this->eastRoom;
}
BaseRoom* BaseRoom::getWestRoom() {
	return this->westRoom;
}
#pragma endregion

std::string BaseRoom::toString() {
	return std::string(
		std::string("Base Room (") +
		std::to_string(this->getRow()) +
		std::string(",") +
		std::to_string(this->getColumn()) + 
		std::string(",") +
		std::to_string(this->getLevel()) + 
		std::string(")")
		);
}

BaseRoom::~BaseRoom(void)
{
}
