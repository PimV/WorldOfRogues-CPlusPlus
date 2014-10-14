#pragma once
#include "View.h"

#include <string>
#include <vector>
#include <iostream>

class BaseRoom;

class Game
{
public:
	Game();
	~Game();
	std::vector<std::vector<std::vector<BaseRoom*> > > roomVector;

private:
	View *view;
	void createVector();
	void displayMap();
};



