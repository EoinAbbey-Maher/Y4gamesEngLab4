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
			m_isRunning = true;
		}
		else
		{
			m_isRunning = false;
		}
	}
}

void Game::loadContent()
{
	DEBUG_MSG("Loading Content");
	m_surface = SDL_LoadBMP("ASSETS\\IMAGES\\sprite1.bmp");
	m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

	if (SDL_QueryTexture(m_texture, NULL, NULL, &m_source.w, &m_destination.h) == 0)
	{
		m_destination.x = m_source.x;
		m_destination.y = m_source.y;
		m_destination.w = m_source.w;
		m_destination.h = m_source.h;	
	}
	else
	{
		std::cout << "Texture Failed" << std::endl;
		m_isRunning = false;
	}
}

void Game::unloadContent()
{
}

void Game::processEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

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
	SDL_RenderPresent(m_renderer);

}

void Game::cleanup()
{
	SDL_DestroyWindow(m_window);
	SDL_DestroyRenderer(m_renderer);
	SDL_Quit();
	std::cout << "Game Cleaned" << std::endl;
}
