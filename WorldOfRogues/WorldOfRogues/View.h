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
	void displayInventory();
	void displayEquipment();
	void enterDoor(std::string prefix, std::string input);
private:
	Game* game;
	std::string input;

	
};

