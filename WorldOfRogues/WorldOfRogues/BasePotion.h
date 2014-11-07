#pragma once
#include "BaseItem.h"
class BasePotion
	: public BaseItem
{
public:
	BasePotion(void);

	void setHealth(int health);
	void setExperience(int experience);
	void setMana(int mana);

	int getHealth();
	int getExperience();
	int getMana();

	void use(Player* player);

	~BasePotion(void);
private:
	int health;
	int mana;
	int experience;
};

