#pragma once
#include <string>
class BaseItem
{
public:
	BaseItem(void);
	virtual std::string toString() = 0;

	virtual ~BaseItem(void);

protected:
	std::string Name;

};

