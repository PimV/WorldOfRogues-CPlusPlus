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

	virtual void generateDoors();

	bool hasNorthDoor();
	bool hasSouthDoor();
	bool hasEastDoor();
	bool hasWestDoor();

	void enableNorthDoor();
	void enableSouthDoor();
	void enableWestDoor();
	void enableEastDoor();

	void disableNorthDoor();
	void disableSouthDoor();
	void disableWestDoor();
	void disableEastDoor();

	int getDoorCount();
	std::string getAvailableDoorString();

	void setRow(int row);
	void setColumn(int column);
	void setLevel(int level);
	int getRow();
	int getColumn();
	int getLevel();

	virtual std::string toString();

	virtual void setSymbol(char* c);
	virtual char* getSymbol();

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

	char* symbol;
};

