#include "Player.h"


Player::Player(void)
{
}


void Player::setMaxLevelVisited(int maxLevelVisited) {
	this->maxLevelVisited = maxLevelVisited;
}

int Player::getMaxLevelVisited() {
	return this->maxLevelVisited;
}

Player::~Player(void)
{
}
