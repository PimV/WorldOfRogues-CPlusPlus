#include "ItemFactory.h"

#include "Weapon.h"
#include "Shield.h"
#include "Platelegs.h"
#include "Platebody.h"
#include "Helmet.h"

#include "HealthPotion.h"
//#include "ManaPotion.h"
#include "ExperiencePotion.h"

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
		std::uniform_int_distribution<int> dist2(1, 8);
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
		case 6:
			itemsArray.push_back(createItem(ItemType::HealthPotion));
			break;
		case 7:
			itemsArray.push_back(createItem(ItemType::ManaPotion));
			break;
		case 8:
			itemsArray.push_back(createItem(ItemType::ExperiencePotion));
			break;
		default:
			break;
		}
	}

	return itemsArray;
}

BaseItem* ItemFactory::createItem(ItemType it)
{
	//BaseItem* item;

	switch (it)
	{
	case ItemType::Sword: 
		{
			Weapon* item = new Weapon();
			item->name = "The Ripper";
			item->attackpoints = 10;
			return item;
		} 
	case ItemType::Shield:
		{
			Shield* item = new Shield();
			item->name = "Mirror Shield";
			item->defencepoints = 10;
			return item;
		}
	case ItemType::Helmet:
		{
			Helmet* item = new Helmet();
			item->name = "Highmage Mask";
			item->defencepoints = 10;
			return item;
		}
	case ItemType::Platebody:
		{
			Platebody* item = new Platebody();
			item->name = "Steel armour";
			item->defencepoints = 10;
			return item;
		}
	case ItemType::Platelegs:
		{
			Platelegs* item = new Platelegs();
			item->name = "Iron legs";
			item->defencepoints = 10;
			return item;
		}
	case ItemType::HealthPotion: 
		{
			HealthPotion* item = new HealthPotion();
			return item;
		}
	case ItemType::ManaPotion:
		{
			//ManaPotion* item = new ManaPotion();
			//return item;
			//break;
		}
	case ItemType::ExperiencePotion: 
		{
			ExperiencePotion* item = new ExperiencePotion();
			return item;

		}
	default:
		return nullptr;
		break;
	}


}