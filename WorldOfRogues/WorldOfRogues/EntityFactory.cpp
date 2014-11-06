#include "EntityFactory.h"

#include "BaseEntity.h"
#include "Dwarf.h"
#include "Rat.h"
#include "Skeleton.h"
#include "Zombie.h"
#include "Boss.h"
#include "Player.h"

#include "BaseEquipment.h"
#include "BaseInventory.h"

#include "Game.h"

#include <random>




EntityFactory::~EntityFactory()
{
}

std::vector<BaseEntity*> EntityFactory::createEntitiesForRoom()
{
	std::vector<BaseEntity*> entityArray;

	std::random_device dev;
	std::default_random_engine dre(dev());

	// random amount
	std::uniform_int_distribution<int> dist1(1, 4);
	int amountOfEntities = dist1(dre);
	std::cout << "Random amount of entities [" << amountOfEntities << "]" << std::endl;

	// random mobs
	for (size_t i = 0; i < amountOfEntities; i++)
	{
		std::uniform_int_distribution<int> dist2(1, 5);
		int randomEntitySpawn = dist2(dre);

		std::cout << "Created: ";
		switch (randomEntitySpawn)
		{
		case 1:
			std::cout << "Rat ";
			entityArray.push_back(createEntity(EntityType::Rat));
			break;
		case 2:
			std::cout << "Skeleton ";
			entityArray.push_back(createEntity(EntityType::Skeleton));
			break;
		case 3:
			std::cout << "Zombie ";
			entityArray.push_back(createEntity(EntityType::Zombie));
			break;
		case 4:
			std::cout << "Dwarf ";
			entityArray.push_back(createEntity(EntityType::Dwarf));
			break;
		case 5:
			std::cout << "Boss ";
			entityArray.push_back(createEntity(EntityType::Boss));
			break;
		default:
			break;
		}

		std::cout << std::endl;
	}

	// random entity level + name
	for (BaseEntity *e : entityArray)
	{
		std::uniform_int_distribution<int> dist3(1, 5);
		int randomEntityLevel = dist3(dre);
		std::cout << "Random entity level [" << randomEntityLevel << "]" << std::endl;

		// change: (CurrentPlayer->getLevel() + randomEntityLevel);
		e->setLevel(randomEntityLevel);
		e->setName(EntityFactory::generateName(e));
	}

	return entityArray;
}

BaseEntity* EntityFactory::createEntity(EntityType et)
{
	switch (et)
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
	}
}

std::string EntityFactory::generateName(BaseEntity* entity) {
	std::string name = "";

	switch( entity->getLevel() - Game::Instance()->getPlayer()->getLevel()) {
	case -5:
	case -4:
	case -3:
	case -2:
	case -1:
		name.append("A weak ");
		break;
	case 1:
	case 2:
		name.append("An angry ");
		break;
	case 3:
	case 4:
		name.append("A mighty ");
		break;
	case 5:
	case 6:
		name.append("A giant ");
		break;
	case 7:
	case 8:
		name.append("A super-sized ");
		break;
	default:
		name.append("A regular ");
		break;
	}

	name.append(entity_strings[(int)entity->getEntityType()]);

	return name;
}