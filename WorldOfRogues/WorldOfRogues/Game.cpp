#include "Game.h"
#include "BaseRoom.h"
#include "RoomFactory.h"
#include "Direction.h"

#include <iostream>
#include <vector>


Game::Game()
{
	input = "help";
	createVector();
}

void Game::createVector()
{
	int width = 10;
	int height = 10;
	int depth = 10;

	std::vector<std::vector<std::vector<BaseRoom*> > > roomVector;

	roomVector.resize(width);
	for (int a = 0; a < width; a++){
		roomVector[a].resize(height);
		for (int b = 0; b < height; b++) {
			roomVector[a][b].resize(depth);
		}
	}
	RoomFactory rf;

	roomVector[1][2][3] = new BaseRoom(1, 2, 3);
	roomVector[1][3][3] = rf.createRoom(roomVector[1][2][3], Direction::East);
	
	
	while (input != "quit")
	{
		if (input == "help")
		{
			std::cout << "Please use one of the following commands:\n";
			std::cout << "- map\n";
			std::cout << "- examine room\n";
			std::cout << "- enter north door\n";
			std::cout << "- enter south door\n";
			std::cout << "- enter east door\n";
			std::cout << "- enter west door\n";
		}
		else if (input == "map") 
		{
			std::cout << "Display map!\n";
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

Game::~Game(void)
{
}
