#pragma once
#include "BaseEntity.h"
#include "BaseItem.h"

#include <iostream>
#include <string>
#include <vector>

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

	bool hasTrap();
	void enableTrap();
	void disableTrap();
	bool trapPlayer(BaseEntity* player);

	int getDoorCount();
	std::string getAvailableDoorString();

	void setRow(int row);
	void setColumn(int column);
	void setLevel(int level);
	int getRow();
	int getColumn();
	int getLevel();

	void addEnemy(BaseEntity* entity);
	void addEnemies(std::vector<BaseEntity*> enemies);
	void setEnemies(std::vector<BaseEntity*> enemies);

	void addItem(BaseItem* item);
	void addItems(std::vector<BaseItem*> items);
	void setItems(std::vector<BaseItem*> items);

	std::vector<BaseEntity*> getEnemies();
	std::vector<BaseItem*> getItems();

	bool hasEnemies();

	void setDescription(std::string description);
	std::string getDescription();

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

	bool trapped;
	bool trapFound;

	int row;
	int column;
	int level;

	std::vector<BaseEntity*> enemies;
	std::vector<BaseItem*> items;

	std::string description;

	char* symbol;
};

