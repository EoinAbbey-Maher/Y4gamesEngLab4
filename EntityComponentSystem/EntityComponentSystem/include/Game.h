#ifndef GAME_HPP
#define GAME_HPP
	
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>

class Game
{
public:
	Game();
	~Game();

	void init(const char* t_title, int t_xpos, int t_ypos, int t_width, int t_height, bool t_isFullScreen);
	void loadContent();
	void unloadContent();

	void processEvents();

	bool isRunning();

	void update();

	void render();
	void cleanup();

	
private:
	bool m_isRunning{ false };


	SDL_Window * m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	SDL_Surface* m_surface;

	SDL_Rect m_source;
	SDL_Rect m_destination;
};

#endif // !GAME_HPP

