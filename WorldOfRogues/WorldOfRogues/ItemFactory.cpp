#include "ItemFactory.h"
#include "ItemType.h"

#include "Weapon.h"
#include "Shield.h"
#include "Platelegs.h"
#include "Platebody.h"
#include "Helmet.h"

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
	std::cout << "Random amount of items [" << amountOfItems << "]" << std::endl;

	// random items
	for (size_t i = 0; i < amountOfItems; i++)
	{
		std::uniform_int_distribution<int> dist2(1, 5);
		int randomItemSpawn = dist2(dre);

		std::cout << "Created: ";
		switch (randomItemSpawn)
		{
		case 1:
			std::cout << "Sword ";
			itemsArray.push_back(createItem(ItemType::Sword));
			break;
		case 2:
			std::cout << "Shield ";
			itemsArray.push_back(createItem(ItemType::Shield));
			break;
		case 3:
			std::cout << "Helmet ";
			itemsArray.push_back(createItem(ItemType::Helmet));
			break;
		case 4:
			std::cout << "Plate armour ";
			itemsArray.push_back(createItem(ItemType::PlateArmour));
			break;
		case 5:
			std::cout << "Plate legs ";
			itemsArray.push_back(createItem(ItemType::PlateLegs));
			break;
		default:
			break;
		}

		std::cout << std::endl;
	}

	//// random entity level
	//for (BaseEntity *e : entityArray)
	//{
	//	std::uniform_int_distribution<int> dist3(1, 5);
	//	int randomEntityLevel = dist3(dre);
	//	std::cout << "Random entity level [" << randomEntityLevel << "]" << std::endl;

	//	// change: (CurrentPlayer->getLevel() + randomEntityLevel);
	//	e->setLevel(randomEntityLevel);
	//}

	return itemsArray;
}

BaseItem* ItemFactory::createItem(ItemType it)
{
	switch (it)
	{
	case ItemType::Sword:
		return new Weapon();
		break;
	case ItemType::Shield:
		return new Shield();
		break;
	case ItemType::Helmet:
		return new Helmet();
		break;
	case ItemType::PlateArmour:
		return new Platebody();
		break;
	case ItemType::PlateLegs:
		return new Platelegs();
		break;
	default:
		return nullptr;
		break;
	}
}