#ifndef GAME_HPP
#define GAME_HPP
	
#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include <SDL_image.h>

#include "Component.h"
#include "Entity.h"
#include "System.h"


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


	Entity m_player;
	Entity m_cat;
	Entity m_dog;
	Entity m_alien;

	HealthSystem m_healthSystem;
	ControlSystem m_controlSystem;
	AiSystem m_aiSystem;
	RenderSystem m_renderSystem;

	Component* m_playerHealthComponent = new HealthComponent();
	Component* m_alienHealthComponent = new HealthComponent();
	Component* m_dogHealthComponent = new HealthComponent();
	
	Component* m_playerPositionComponent = new PositionComponent(100, 50);
	Component* m_alienPositionComponent = new PositionComponent( 150, 255);
	Component* m_dogPositionComponent = new PositionComponent( 450, 400);
	Component* m_catPositionComponent = new PositionComponent(500 , 500);
	
	Component* m_inputComponent = new InputComponent();


	SDL_Window * m_window;
	SDL_Renderer* m_renderer;
	SDL_Texture* m_texture;
	SDL_Surface* m_surface;

	SDL_Rect m_source;
	SDL_Rect m_destination;
};

#endif // !GAME_HPP

