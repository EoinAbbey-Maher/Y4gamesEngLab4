/// <summary>
/// simple game loop for SFML[2.5.1]
/// 
/// @author Peter Lowe
/// @date May 2019
/// </summary>

#include "Game.h"


using namespace std;

Game* game = nullptr;

int main(int argc, char** argv)
{

	game = new Game();

	game->init("lab3 SDL FSM", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

	game->loadContent();

	while (game->isRunning())
	{
		game->processEvents();
		game->update();
		game->render();

	}

	game->cleanup();
	game->unloadContent();

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Quit();
	
	std::cin.get();

	return 1; // success
}