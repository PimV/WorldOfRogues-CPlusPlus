#pragma once
#include <string>
class BaseItem
{
public:
	BaseItem(void);
	virtual ~BaseItem(void);

	std::string toString();
protected:
	std::string Name;

};

