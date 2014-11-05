#include "EntityFactory.h"

#include "BaseEntity.h"
#include "Dwarf.h"
#include "Rat.h"
#include "Skeleton.h"
#include "Zombie.h"
#include "Boss.h"

#include <random>


EntityFactory::EntityFactory()
{
}


EntityFactory::~EntityFactory()
{
}

std::vector<BaseEntity*> EntityFactory::createEntitiesForRoom(BaseRoom *br)
{
	std::vector<BaseEntity*> entityArray;

	std::random_device dev;
	std::default_random_engine dre(dev());

	// random amount
	std::uniform_int_distribution<int> dist1(1, 4);
	int amountOfEntities = dist1(dre);

	// random mobs
	for (size_t i = 0; i < amountOfEntities; i++)
	{
		std::uniform_int_distribution<int> dist2(1, 5);
		int randomEntitySpawn = dist2(dre);

		switch (randomEntitySpawn)
		{
		case 1:
			entityArray.push_back(createEntity(EntityTypes::Rat));
			break;
		case 2:
			entityArray.push_back(createEntity(EntityTypes::Skeleton));
			break;
		case 3:
			entityArray.push_back(createEntity(EntityTypes::Zombie));
			break;
		case 4:
			entityArray.push_back(createEntity(EntityTypes::Dwarf));
			break;
		case 5:
			entityArray.push_back(createEntity(EntityTypes::Boss));
			break;
		default:
			break;
		}
	}

	// random entity level
	for (BaseEntity *e : entityArray)
	{
		// change: between current player level - 2 & +3
		std::uniform_int_distribution<int> dist3(1, 5);
		int randomEntityLevel = dist3(dre);

		switch (randomEntityLevel)
		{
		case 1:
			//e->setLevel(1);
			break;
		case 2:
			//e->setLevel(2);
			break;
		case 3:
			//e->setLevel(3);
			break;
		case 4:
			//e->setLevel(4);
			break;
		case 5:
			//e->setLevel(5);
			break;
		default:
			break;
		}
	}

	return entityArray;
}

BaseEntity* EntityFactory::createEntity(EntityTypes et)
{
	switch (et)
	{
	case EntityTypes::Rat:
		return new Rat();
		break;
	case EntityTypes::Zombie:
		return new Zombie();
		break;
	case EntityTypes::Skeleton:
		return new Skeleton();
		break;
	case EntityTypes::Dwarf:
		return new Dwarf();
		break;
	case EntityTypes::Boss:
		return new Boss();
		break;
	case EntityTypes::Player:
		///
		break;
	default:
		break;
	}
}
