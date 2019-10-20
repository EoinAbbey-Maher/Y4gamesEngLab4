#include "Game.h"
#include "Debug.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::init(const char* t_title, int t_xpos, int t_ypos, int t_width, int t_height, bool t_isFullScreen)
{
	int flags = 0;
	if (t_isFullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialised " << std::endl;

		m_window = SDL_CreateWindow(t_title, t_xpos, t_ypos, t_width, t_height, flags);

		if (m_window)
		{
			std::cout << "window created" << std::endl;
		}
			m_renderer = SDL_CreateRenderer(m_window, -1, 0);
		if (m_renderer)
		{
			SDL_SetRenderDrawColor(m_renderer, 255, 255, 255, 255);

			m_player.setRenderer(*m_renderer);
			m_alien.setRenderer(*m_renderer);
			m_dog.setRenderer(*m_renderer);
			m_cat.setRenderer(*m_renderer);
			m_renderSystem.setRenderer(m_renderer);

			m_isRunning = true;
		}
		else
		{
			m_isRunning = false;
		}
	}

	loadContent();

	/// <summary>
	/// Setting up Systems and Components
	/// </summary>
	m_player.setId("Player");
	m_player.addComponent(m_playerHealthComponent);
	m_player.addComponent(m_playerPositionComponent);
	m_player.addComponent(m_inputComponent);
	
	m_alien.setId("Alien");
	m_alien.addComponent(m_alienHealthComponent);
	m_alien.addComponent(m_alienPositionComponent);

	m_dog.setId("Dog");
	m_dog.addComponent(m_dogHealthComponent);
	m_dog.addComponent(m_dogPositionComponent);

	m_cat.setId("Cat");
	m_cat.addComponent(m_catPositionComponent);

	m_healthSystem.addEntity(m_alien);
	m_healthSystem.addEntity(m_player);
	m_healthSystem.addEntity(m_dog);

	m_renderSystem.addEntity(m_alien);
	m_renderSystem.addEntity(m_dog);
	m_renderSystem.addEntity(m_player);
	m_renderSystem.addEntity(m_cat);

	m_controlSystem.addEntity(m_player);
	
}

void Game::loadContent()
{
	DEBUG_MSG("Loading Content");
	m_player.setTextureName("ASSETS\\IMAGES\\zombie.bmp");
	m_alien.setTextureName("ASSETS\\IMAGES\\alien.bmp");
	m_dog.setTextureName("ASSETS\\IMAGES\\dog.bmp");
	m_cat.setTextureName("ASSETS\\IMAGES\\cat.bmp");


	/*m_cat.m_surface = SDL_LoadBMP("ASSETS\\IMAGES\\zombie.bmp");
	m_cat.m_texture = SDL_CreateTextureFromSurface(m_renderer, m_player.m_surface);

	m_alien.m_surface = SDL_LoadBMP("ASSETS\\IMAGES\\zombie.bmp");
	m_alien.m_texture = SDL_CreateTextureFromSurface(m_renderer, m_player.m_surface);

	m_dog.m_surface = SDL_LoadBMP("ASSETS\\IMAGES\\zombie.bmp");
	m_dog.m_texture = SDL_CreateTextureFromSurface(m_renderer, m_player.m_surface);

	if (m_player.m_texture != nullptr)
	{
		std::cout << "Texture loaded" << std::endl;
	}
	else
	{
		std::cout << "Texture Failed" << std::endl;
	}*/
}

void Game::unloadContent()
{
}

void Game::processEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	m_controlSystem.update(event);
	switch (event.type)
	{
	case SDL_QUIT:
		m_isRunning = false;
		break;
	default:
		break;
	}
}

bool Game::isRunning()
{
	return m_isRunning;
}

void Game::update()
{
	m_healthSystem.update();
}

void Game::render()
{


	SDL_RenderClear(m_renderer);
	//if (m_renderer != nullptr && m_texture != nullptr)
	//{
	//	SDL_Rect* testRect = new SDL_Rect();
	//	testRect->x = 0;
	//	testRect->y = 0;
	//	testRect->h = 32;
	//	testRect->w = 32;
	//	SDL_RenderCopy(m_renderer, m_texture, testRect , NULL);
	//}


	m_renderSystem.update();
	
	SDL_RenderPresent(m_renderer);

}

void Game::cleanup()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
