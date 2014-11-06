#include "ItemFactory.h"

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
	//std::cout << "Random amount of items [" << amountOfItems << "]" << std::endl;

	// random items
	for (size_t i = 0; i < amountOfItems; i++)
	{
		std::uniform_int_distribution<int> dist2(1, 5);
		int randomItemSpawn = dist2(dre);

		//std::cout << "Created: ";
		switch (randomItemSpawn)
		{
		case 1:
			itemsArray.push_back(createItem(ItemType::Sword));
			break;
		case 2:
			itemsArray.push_back(createItem(ItemType::Shield));
			break;
		case 3:
			itemsArray.push_back(createItem(ItemType::Helmet));
			break;
		case 4:
			itemsArray.push_back(createItem(ItemType::Platebody));
			break;
		case 5:
			itemsArray.push_back(createItem(ItemType::Platelegs));
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
	BaseItem* item;

	switch (it)
	{
	case ItemType::Sword:
		item = new Weapon();
		item->Name = "The Ripper";
		dynamic_cast<Weapon*>(item)->attackpoints = 10;
		break;
	case ItemType::Shield:
		item = new Shield();
		item->Name = "Mirror Shield";
		dynamic_cast<Shield*>(item)->defencepoints = 10;
		break;
	case ItemType::Helmet:
		item = new Helmet();
		item->Name = "Highmage Mask";
		dynamic_cast<Helmet*>(item)->defencepoints = 10;
		break;
	case ItemType::Platebody:
		item = new Platebody();
		item->Name = "Steel armour";
		dynamic_cast<Platebody*>(item)->defencepoints = 10;
		break;
	case ItemType::Platelegs:
		item = new Platelegs();
		item->Name = "Iron legs";
		dynamic_cast<Platelegs*>(item)->defencepoints = 10;
		break;
	default:
		return nullptr;
		break;
	}

	return item;


}