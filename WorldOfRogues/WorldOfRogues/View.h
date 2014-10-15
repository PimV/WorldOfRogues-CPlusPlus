#pragma once
#include <string>

class Game;

class View
{
public:
	View(Game* game);
	virtual ~View();
	
	void receiveInput();

	//Play functions
	void displayMap();
	void enterDoor();
private:
	Game* game;
	std::string input;

	
};

