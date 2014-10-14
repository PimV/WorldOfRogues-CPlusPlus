#pragma once
#include <iostream>
#include <string>
class BaseRoom
{
public:
	BaseRoom(int row, int column, int level);

	void setNorthRoom(BaseRoom* room);
	void setSouthRoom(BaseRoom* room);
	void setEastRoom(BaseRoom* room);
	void setWestRoom(BaseRoom* room);
	BaseRoom* getNorthRoom();
	BaseRoom* getSouthRoom();
	BaseRoom* getEastRoom();
	BaseRoom* getWestRoom();

	void setRow(int row);
	void setColumn(int column);
	void setLevel(int level);
	int getRow();
	int getColumn();
	int getLevel();

	virtual std::string toString();

	virtual ~BaseRoom(void);
private:
	BaseRoom* northRoom;
	BaseRoom* southRoom;
	BaseRoom* eastRoom;
	BaseRoom* westRoom;

	bool northDoor;
	bool southDoor;
	bool eastDoor;
	bool westDoor;

	int row;
	int column;
	int level;
};

