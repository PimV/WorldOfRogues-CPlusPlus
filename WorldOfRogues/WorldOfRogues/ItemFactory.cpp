#include "ItemFactory.h"

#include "Weapon.h"
#include "Shield.h"
#include "Platelegs.h"
#include "Platebody.h"
#include "Helmet.h"
#include "Game.h"

#include <random>

ItemFactory::~ItemFactory()
{
}

std::vector<BaseItem*> ItemFactory::createRandomItems()
{
	std::vector<BaseItem*> itemsArray;

	std::random_device dev;
	std::default_random_engine dre(dev());

	// random amount
	std::uniform_int_distribution<int> dist1(1, 4);
	int amountOfItems = dist1(dre);
	//std::cout << "Random amount of items [" << amountOfItems << "]" << std::endl;

	// random items
	for (size_t i = 0; i < amountOfItems; i++)
	{
		std::uniform_int_distribution<int> dist2(0, 30);
		int randomItemSpawn = dist2(dre);

		if (randomItemSpawn >= 0 && randomItemSpawn <= 5) {
			itemsArray.push_back(createItem(static_cast<WeaponType>(randomItemSpawn)));
		}
		else if (randomItemSpawn >= 6 && randomItemSpawn <= 9) {
			itemsArray.push_back(createItem(static_cast<ArmourType>(randomItemSpawn)));
		}
	}

	return itemsArray;
}

BaseItem* ItemFactory::createItem(WeaponType weaponType)
{
	BaseWeapon *item = new Weapon();
	item->setType(weaponType);
	calculateLevel(item);
	setNameAndLevel(item);
	return item;
}

BaseItem* ItemFactory::createItem(ArmourType armourType)
{
	BaseArmour* item;

	switch (armourType)
	{
	case ArmourType::Helmet:
		item = new Helmet();
		break;
	case ArmourType::Legs:
		item = new Platelegs();
		break;
	case ArmourType::Body:
		item = new Platebody();
		break;
	case ArmourType::Shield:
		item = new Shield();
		break;
	default:
		return nullptr;
	}

	item->setType(armourType);
	calculateLevel(item);
	setNameAndLevel(item);
	return item;
}

void ItemFactory::setNameAndLevel(BaseArmour* item) {
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 10);
	int randomNumberForNames = dist1(dre);

	std::string name = "";

	switch (randomNumberForNames)
	{
	case 1:
		name.append("Broken ");
		(item->getLevel() - 4 >= 1) ? item->setLevel(item->getLevel() - 4) : item->setLevel(1);
		item->setDefencePoints(1);
		break;
	case 2:
		name.append("Worn-out ");
		(item->getLevel() - 3 >= 1) ? item->setLevel(item->getLevel() - 3) : item->setLevel(1);
		item->setDefencePoints(2);
		break;
	case 3:
		name.append("Rusty ");
		(item->getLevel() - 2 >= 1) ? item->setLevel(item->getLevel() - 2) : item->setLevel(1);
		item->setDefencePoints(3);
		break;
	case 4:
		name.append("Used ");
		(item->getLevel() - 1 >= 1) ? item->setLevel(item->getLevel() - 1) : item->setLevel(1);
		item->setDefencePoints(4);
		break;
	case 5:
		name.append("Common ");
		item->setDefencePoints(5);
		break;
	case 6:
		name.append("Sturdy ");
		item->setLevel(item->getLevel() + 1);
		item->setDefencePoints(6);
		break;
	case 7:
		name.append("Excellent ");
		item->setLevel(item->getLevel() + 2);
		item->setDefencePoints(7);
		break;
	case 8:
		name.append("Enchanted ");
		item->setLevel(item->getLevel() + 3);
		item->setDefencePoints(8);
		break;
	case 9:
		name.append("Unique ");
		item->setLevel(item->getLevel() + 4);
		item->setDefencePoints(9);
		break;
	case 10:
		name.append("Royal ");
		item->setLevel(item->getLevel() + 5);
		item->setDefencePoints(10);
		break;
	default:
		break;
	}

	std::uniform_int_distribution<int> dist2(1, 5);
	int randomNumberForType = dist2(dre);

	switch (randomNumberForType)
	{
	case 1:
		name.append("Bronze ");
		item->setLevel(item->getLevel() + 1);
		item->setDefencePoints(item->getDefencePoints() + 1);
		break;
	case 2:
		name.append("Iron ");
		item->setLevel(item->getLevel() + 2);
		item->setDefencePoints(item->getDefencePoints() + 2);
		break;
	case 3:
		name.append("Steel ");
		item->setLevel(item->getLevel() + 3);
		item->setDefencePoints(item->getDefencePoints() + 3);
		break;
	case 4:
		name.append("Mithril ");
		item->setLevel(item->getLevel() + 4);
		item->setDefencePoints(item->getDefencePoints() + 4);
		break;
	case 5:
		name.append("Adamantium ");
		item->setLevel(item->getLevel() + 5);
		item->setDefencePoints(item->getDefencePoints() + 5);
		break;
	default:
		break;
	}

	name.append(item_strings[(int)item->getType()]);
	item->setName(name);
}

void ItemFactory::setNameAndLevel(BaseWeapon* item) {
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(1, 10);
	int randomNumberForNames = dist1(dre);
	
	std::string name = "";

	switch (randomNumberForNames)
	{
	case 1:
		name.append("Broken ");
		(item->getLevel() - 4 >= 1) ? item->setLevel(item->getLevel() - 4) : item->setLevel(1);
		item->setAttackPoints(1);
		break;
	case 2:
		name.append("Worn-out ");
		(item->getLevel() - 3 >= 1) ? item->setLevel(item->getLevel() - 3) : item->setLevel(1);
		item->setAttackPoints(2);
		break;
	case 3:
		name.append("Rusty ");
		(item->getLevel() - 2 >= 1) ? item->setLevel(item->getLevel() - 2) : item->setLevel(1);
		item->setAttackPoints(3);
		break;
	case 4:
		name.append("Used ");
		(item->getLevel() - 1 >= 1) ? item->setLevel(item->getLevel() - 1) : item->setLevel(1);
		item->setAttackPoints(4);
		break;
	case 5:
		name.append("Common ");
		item->setAttackPoints(5);
		break;
	case 6:
		name.append("Sturdy ");
		item->setLevel(item->getLevel() + 1);
		item->setAttackPoints(6);
		break;
	case 7:
		name.append("Excellent ");
		item->setLevel(item->getLevel() + 2);
		item->setAttackPoints(7);
		break;
	case 8:
		name.append("Enchanted ");
		item->setLevel(item->getLevel() + 3);
		item->setAttackPoints(8);
		break;
	case 9:
		name.append("Unique ");
		item->setLevel(item->getLevel() + 4);
		item->setAttackPoints(9);
		break;
	case 10:
		name.append("Royal ");
		item->setLevel(item->getLevel() + 5);
		item->setAttackPoints(10);
		break;
	default:
		break;
	}

	std::uniform_int_distribution<int> dist2(1, 5);
	int randomNumberForType = dist2(dre);

	switch (randomNumberForType)
	{
	case 1:
		name.append("Bronze ");
		item->setLevel(item->getLevel() + 1);
		item->setAttackPoints(item->getAttackPoints() + 1);
		break;
	case 2:
		name.append("Iron ");
		item->setLevel(item->getLevel() + 2);
		item->setAttackPoints(item->getAttackPoints() + 2);
		break;
	case 3:
		name.append("Steel ");
		item->setLevel(item->getLevel() + 3);
		item->setAttackPoints(item->getAttackPoints() + 3);
		break;
	case 4:
		name.append("Mithril ");
		item->setLevel(item->getLevel() + 4);
		item->setAttackPoints(item->getAttackPoints() + 4);
		break;
	case 5:
		name.append("Adamantium ");
		item->setLevel(item->getLevel() + 5);
		item->setAttackPoints(item->getAttackPoints() + 5);
		break;
	default:
		break;
	}

	name.append(item_strings[(int)item->getType()]);
	item->setName(name);
}

void ItemFactory::calculateLevel(BaseItem* item) 
{
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist1(-3, 3);
	int randomDifferenceInLevel = dist1(dre);

	int level = Game::Instance()->getPlayer()->getLevel() - randomDifferenceInLevel;

	if (level >= 1) {
		item->setLevel(level);
	}
	else {
		item->setLevel(1);
	}
	
}