#include "Player.h"


Player::Player(void)
{
}


void Player::setMaxLevelVisited(int maxLevelVisited) {
	if (maxLevelVisited > this->maxLevelVisited) {
		this->maxLevelVisited = maxLevelVisited;
	}
}

int Player::getMaxLevelVisited() {
	return this->maxLevelVisited;
}

std::string Player::toString() {
	return std::string(
		std::string("Player L") +
		std::to_string(this->getLevel())
		);
}


Player::~Player(void)
{
}
