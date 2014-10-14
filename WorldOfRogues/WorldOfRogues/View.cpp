#include "View.h"
#include "Game.h"

View::View(Game* game)
{
	this->game = game;
	input = "help";
}

void View::receiveInput()
{
	while (input != "quit")
	{
		if (input == "help")
		{
			std::cout << "Please use one of the following commands:\n";
			std::cout << "- map\n";
			std::cout << "- examine room\n";
			std::cout << "- quit\n";
			std::cout << "- enter north door\n";
			std::cout << "- enter south door\n";
			std::cout << "- enter east door\n";
			std::cout << "- enter west door\n";
		}
		else if (input == "map")
		{
			displayMap();
		}
		else if (input == "examine room")
		{
			std::cout << "Show everything in this room\n";
		}
		else if (input == "enter north door")
		{
			std::cout << "Enter north door!\n";
		}
		else if (input == "enter south door")
		{
			std::cout << "Enter south door!\n";
		}
		else if (input == "enter east door")
		{
			std::cout << "Enter east door!\n";
		}
		else if (input == "enter west door")
		{
			std::cout << "Enter west door\n";
		}
		else
		{
			std::cout << "Unknown command: '" << input << "'.\n Type 'help' for more information.\n";
		}

		std::cout << "> ";

		std::getline(std::cin, input);
	}
}

void View::displayMap()
{
	// change currentLevel
	size_t currentLevel = 1;
	for (size_t i = 0; i < this->game->roomVector[currentLevel].size(); i++)
	{
		for (size_t j = 0; j < this->game->roomVector[currentLevel][i].size(); j++)
		{
			std::cout << "+";
		}
		std::cout << "\n";
	}
}


View::~View()
{
}
