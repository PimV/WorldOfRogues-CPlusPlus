#pragma once
#include "baseentity.h"
class Player :
	public BaseEntity
{
public:
	Player(void);

	void setRoom(BaseRoom* room) override;

	bool flee();
	bool rest();

	void setExperience(int experience) override;

	void setSkillPoints(int skillPoints);
	int getSkillPoints();

	void setMaxLevelVisited(int maxLevelVisited);
	int getMaxLevelVisited();

	void setHitpoints(int hitpoints) override;

	BaseRoom* getPreviousRoom();
	void setPreviousRoom(BaseRoom* prevRoom);


	std::string toString();

	virtual ~Player(void);

private:
	int skillpoints;
	int maxLevelVisited;
	BaseRoom* prevRoom;
};

