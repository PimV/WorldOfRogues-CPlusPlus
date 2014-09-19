#pragma once
#include <string>

class BaseEntity
{
public:
	BaseEntity(void);
	virtual ~BaseEntity(void);

protected:
	std::string Name;
	int level;
	int hitpoints;
	int attackpoints;
	//Inventory

private:
};

