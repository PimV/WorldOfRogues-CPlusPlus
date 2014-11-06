#include "ItemFactory.h"

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
		//case 1:
		//	std::cout << "Dragon Helmet ";
		//	itemsArray.push_back(createEntity(EntityType::Rat));
		//	break;
		//case 2:
		//	std::cout << "Dragon Plate Armour ";
		//	itemsArray.push_back(createEntity(EntityType::Skeleton));
		//	break;
		//case 3:
		//	std::cout << "Dragon Plate legs ";
		//	itemsArray.push_back(createItem(EntityType::Zombie));
		//	break;
		//case 4:
		//	std::cout << "Dragon sword";
		//	itemsArray.push_back(createItem(EntityType::Dwarf));
		//	break;
		//case 5:
		//	std::cout << "Dragon shield ";
		//	itemsArray.push_back(createItem(EntityType::Boss));
		//	break;
		//default:
		//	break;
		}

	//	std::cout << std::endl;
	//}

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

BaseItem* ItemFactory::createItem(std::string *item)
{
	/*switch (et)
	{
	case EntityType::Rat:
		return new Rat();
		break;
	case EntityType::Zombie:
		return new Zombie();
		break;
	case EntityType::Skeleton:
		return new Skeleton();
		break;
	case EntityType::Dwarf:
		return new Dwarf();
		break;
	case EntityType::Boss:
		return new Boss();
		break;
	case EntityType::Player:
		return new Player();
		break;
	default:
		return nullptr;
		break;
	}*/

	return nullptr;
}