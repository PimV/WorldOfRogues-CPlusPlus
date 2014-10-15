#include "View.h"
#include "Game.h"
#include "BaseRoom.h"

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

		std::cout << "\n> ";

		std::getline(std::cin, input);
	}
}

void View::displayMap()
{
	// change currentLevel
	size_t currentLevel = 0;
	for (size_t i = 0; i < this->game->roomVector[currentLevel].size(); i++)
	{
		std::string northDoors = "";
		std::string roomsAndDoors = "";
		std::string southDoors = "";

		for (size_t j = 0; j < this->game->roomVector[currentLevel][i].size(); j++)
		{

			if (this->game->roomVector[currentLevel][i][j] != nullptr)
			{
				if (this->game->roomVector[currentLevel][i][j]->hasWestDoor()) {
					roomsAndDoors += "-";
				} else {
					roomsAndDoors += " ";
				}
				roomsAndDoors += this->game->roomVector[currentLevel][i][j]->getSymbol();
				//std::cout << this->game->roomVector[currentLevel][i][j]->getSymbol();
				if (this->game->roomVector[currentLevel][i][j]->hasEastDoor()) {
					roomsAndDoors += "-";
					//std::cout << "-";
				} else {
					roomsAndDoors += " ";
					//std::cout << " ";
				}



				if (this->game->roomVector[currentLevel][i][j]->hasSouthDoor()) {
					southDoors += " | ";
				} else {
					southDoors += "   ";
				}

				if (this->game->roomVector[currentLevel][i][j]->hasNorthDoor()) {
					northDoors += " | ";
				} else {
					northDoors += "   ";
				}
			}
			else
			{
				northDoors += "   ";
				southDoors += "   ";
				roomsAndDoors += " . ";
				//std::cout << ". ";
			}
		}
		// print doors:
		std::cout << northDoors << std::endl << roomsAndDoors << std::endl << southDoors << std::endl;
		//std::cout << std::endl << southDoors << std::endl;

	}
}


View::~View()
{
}
