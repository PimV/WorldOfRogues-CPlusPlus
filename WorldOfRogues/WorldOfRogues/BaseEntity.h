#pragma once
#include <string>

class BaseRoom;

class BaseEntity
{
public:
	BaseEntity(void);
	void setRoom(BaseRoom* room);
	BaseRoom* getRoom();
	
	void setLevel(int level);
	int getLevel();

	virtual ~BaseEntity(void);

protected:
	std::string Name;
	int level;
	int hitpoints;
	int attackpoints;
	BaseRoom* room;
	//Inventory

private:
};

