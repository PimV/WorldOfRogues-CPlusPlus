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
		std::uniform_int_distribution<int> dist2(0, 20);
		int randomItemSpawn = dist2(dre);

		if (randomItemSpawn >= 0 && randomItemSpawn <= 8) {
			itemsArray.push_back(createItem(static_cast<WeaponType>(randomItemSpawn)));
		}
		else if (randomItemSpawn >= 9 && randomItemSpawn <= 20) {
			itemsArray.push_back(createItem(static_cast<ArmourType>(randomItemSpawn)));
		}

		std::cout << std::endl;
	}
	return itemsArray;
}

BaseItem* ItemFactory::createItem(WeaponType weaponType)
{
	BaseItem* item;

	switch (weaponType)
	{
	case WeaponType::Dagger:
		item = new Weapon();
		item->Name = "The Ripper";
		dynamic_cast<Weapon*>(item)->attackpoints = 1;
		break;
	case WeaponType::Sword:
		item = new Weapon();
		item->Name = "The Slicer";
		dynamic_cast<Weapon*>(item)->attackpoints = 2;
		break;
	case WeaponType::Axe:
		item = new Weapon();
		item->Name = "The Chopper";
		dynamic_cast<Weapon*>(item)->attackpoints = 3;
		break;
	case WeaponType::Hammer:
		item = new Weapon();
		item->Name = "The Squasher";
		dynamic_cast<Weapon*>(item)->attackpoints = 4;
		break;
	case WeaponType::Spear:
		item = new Weapon();
		item->Name = "The Stabber";
		dynamic_cast<Weapon*>(item)->attackpoints = 5;
		break;
	case WeaponType::Mace:
		item = new Weapon();
		item->Name = "The Stunner";
		dynamic_cast<Weapon*>(item)->attackpoints = 6;
		break;
	case WeaponType::Longsword:
		item = new Weapon();
		item->Name = "The Executer";
		dynamic_cast<Weapon*>(item)->attackpoints = 7;
		break;
	case WeaponType::Battleaxe:
		item = new Weapon();
		item->Name = "The Cleaver";
		dynamic_cast<Weapon*>(item)->attackpoints = 8;
		break;
	case WeaponType::Greatsword:
		item = new Weapon();
		item->Name = "The Destroyer";
		dynamic_cast<Weapon*>(item)->attackpoints = 8;
		break;
	default:
		break;
	}

	return item;
}

BaseItem* ItemFactory::createItem(ArmourType armourType)
{
	BaseItem* item;

	item->Name = armour_strings[(int)armourType];

	switch (armourType)
	{
	case ArmourType::IronHelmet:
		item = new Helmet();
		dynamic_cast<Helmet*>(item)->defencepoints = 1;
		break;
	case ArmourType::SteelHelmet:
		item = new Helmet();
		dynamic_cast<Helmet*>(item)->defencepoints = 2;
		break;
	case ArmourType::MithrilHelmet:
		item = new Helmet();
		dynamic_cast<Helmet*>(item)->defencepoints = 3;
		break;
	case ArmourType::IronLegs:
		item = new Platelegs();
		dynamic_cast<Platelegs*>(item)->defencepoints = 1;
		break;
	case ArmourType::SteelLegs:
		item = new Platelegs();
		dynamic_cast<Platelegs*>(item)->defencepoints = 2;
		break;
	case ArmourType::MithrilLegs:
		item = new Platelegs();
		dynamic_cast<Platelegs*>(item)->defencepoints = 3;
		break;
	case ArmourType::IronBody:
		item = new Platebody();
		dynamic_cast<Platebody*>(item)->defencepoints = 1;
		break;
	case ArmourType::SteelBody:
		item = new Platebody();
		dynamic_cast<Platebody*>(item)->defencepoints = 2;
		break;
	case ArmourType::MithrilBody:
		item = new Platebody();
		dynamic_cast<Platebody*>(item)->defencepoints = 3;
		break;
	case ArmourType::IronShield:
		item = new Shield();
		dynamic_cast<Shield*>(item)->defencepoints = 1;
		break;
	case ArmourType::SteelShield:
		item = new Shield();
		dynamic_cast<Shield*>(item)->defencepoints = 2;
		break;
	case ArmourType::MithrilShield:
		item = new Shield();
		dynamic_cast<Shield*>(item)->defencepoints = 3;
		break;
	default:
		break;
	}

	return item;
}