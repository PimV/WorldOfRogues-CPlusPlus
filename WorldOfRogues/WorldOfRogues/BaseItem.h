#pragma once
#include <string>
class BaseItem
{
public:
	BaseItem(void);
	virtual ~BaseItem(void);
	
	virtual std::string toString();
	std::string Name;

protected:
};

