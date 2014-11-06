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
	void displayPlayerStatistics();
	void displayCurrentRoom();

	//Actions
	void enterDoor(std::string prefix, std::string input);
	void useItem(std::string prefix, std::string input);
	void unequipItem(std::string prefix, std::string input);
private:
	Game* game;
	std::string input;
	void displayIntroMessage();

};

