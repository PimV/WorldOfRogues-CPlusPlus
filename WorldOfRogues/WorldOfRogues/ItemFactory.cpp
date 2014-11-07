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
		std::uniform_int_distribution<int> dist2(0, 30);
		int randomItemSpawn = dist2(dre);

		if (randomItemSpawn >= 0 && randomItemSpawn <= 8) {
			itemsArray.push_back(createItem(static_cast<WeaponType>(randomItemSpawn)));
		}
		else if (randomItemSpawn >= 9 && randomItemSpawn <= 20) {
			itemsArray.push_back(createItem(static_cast<ArmourType>(randomItemSpawn)));
		}
	}
	return itemsArray;
}

BaseItem* ItemFactory::createItem(WeaponType weaponType)
{
	Weapon *item = new Weapon();

	switch (weaponType)
	{
	case WeaponType::Dagger:
		item->Name = "The Ripper";
		item->attackpoints = 1;
		return item;
	case WeaponType::Sword:
		item->Name = "The Slicer";
		item->attackpoints = 2;
		return item;
	case WeaponType::Axe:
		item->Name = "The Chopper";
		item->attackpoints = 3;
		return item;
	case WeaponType::Hammer:
		item->Name = "The Squasher";
		item->attackpoints = 4;
		return item;
	case WeaponType::Spear:
		item->Name = "The Stabber";
		item->attackpoints = 5;
		return item;
	case WeaponType::Mace:
		item->Name = "The Stunner";
		item->attackpoints = 6;
		return item;
	case WeaponType::Longsword:
		item->Name = "The Executer";
		item->attackpoints = 7;
		return item;
	case WeaponType::Battleaxe:
		item->Name = "The Cleaver";
		item->attackpoints = 8;
		return item;
	case WeaponType::Greatsword:
		item->Name = "The Destroyer";
		item->attackpoints = 9;
		return item;
	default:
		return nullptr;
		break;
	}
}

BaseItem* ItemFactory::createItem(ArmourType armourType)
{
	BaseArmour* item;

	switch (armourType)
	{
	case ArmourType::IronHelmet:
		item = new Helmet();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 1;
		return item;
	case ArmourType::SteelHelmet:
		item = new Helmet();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 2;
		return item;
	case ArmourType::MithrilHelmet:
		item = new Helmet();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 3;
		return item;
	case ArmourType::IronLegs:
		item = new Platelegs();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 1;
		return item;
	case ArmourType::SteelLegs:
		item = new Platelegs();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 2;
		return item;
	case ArmourType::MithrilLegs:
		item = new Platelegs();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 3;
		return item;
	case ArmourType::IronBody:
		item = new Platebody();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 1;
		return item;
	case ArmourType::SteelBody:
		item = new Platebody();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 2;
		return item;
	case ArmourType::MithrilBody:
		item = new Platebody();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 3;
		return item;
	case ArmourType::IronShield:
		item = new Shield();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 1;
		return item;
	case ArmourType::SteelShield:
		item = new Shield();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 2;
		return item;
	case ArmourType::MithrilShield:
		item = new Shield();
		item->Name = item_strings[(int)armourType];
		item->defencepoints = 3;
		return item;
	default:
		return nullptr;
		break;
	}

}

std::string ItemFactory::generateName(BaseWeapon* item) {
	std::random_device dev;
	std::default_random_engine dre(dev());
	std::uniform_int_distribution<int> dist2(1, 10);
	int randomNumberForNames = dist2(dre);
	
	std::string name = "";

	switch (randomNumberForNames)
	{
	case 1:
		name.append("Broken ");
		// set level
		break;
	case 2:
		name.append("Worn-out ");
		break;
	case 3:
		name.append("Rusty ");
		break;
	case 4:
		name.append("Used ");
		break;
	case 5:
		name.append("Common ");
		break;
	case 6:
		name.append("Sturdy ");
		break;
	case 7:
		name.append("Excellent ");
		break;
	case 8:
		name.append("Enchanted ");
		break;
	case 9:
		name.append("Unique ");
		break;
	case 10:
		name.append("Royal ");
		break;
	default:
		break;
	}

	std::uniform_int_distribution<int> dist3(1, 5);
	int randomNumberForType = dist3(dre);

	switch (randomNumberForType)
	{
	case 1:
		name.append("Bronze ");
		// set level
		break;
	case 2:
		name.append("Iron ");
		break;
	case 3:
		name.append("Steel ");
		break;
	case 4:
		name.append("Mithril ");
		break;
	case 5:
		name.append("Adamantium ");
		break;
	default:
		break;
	}

	name.append(item_strings[(int)item->getType()]);

	return name;
}