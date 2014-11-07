#include "HolyHandGrenade.h"
#include "BaseInventory.h"
#include "Player.h"
#include "BaseRoom.h"

HolyHandGrenade::HolyHandGrenade(void)
{
	this->setName("The Holy Hand Grenade");
}

void HolyHandGrenade::use(Player* player) {
	std::vector<BaseEntity*>& vec = player->getRoom()->getEnemies();
	for (auto it = vec.begin(); it != vec.end(); ++it) 
	{ 
		delete *it; 
	}
	vec.clear();
	std::vector<BaseEntity*>(vec).swap(vec);
	player->getRoom()->setEnemies(vec);
	player->getInventory()->removeItem(this, 1);

}

HolyHandGrenade::~HolyHandGrenade(void)
{
}
