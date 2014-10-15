#pragma once
#include <string>

class Game;

class View
{
public:
	View(Game* game);
	virtual ~View();
	
	void receiveInput();
	void displayMap();
private:
	Game* game;
	std::string input;

	
};

