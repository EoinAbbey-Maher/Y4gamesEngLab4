#ifndef SYSTEM_H
#define SYSTEM_H

#include "Component.h"
#include "Entity.h"
#include <vector>

class HealthSystem 
{
	std::vector<Entity> m_entities;
public:
	void addEntity(Entity e)
	{
		m_entities.push_back(e);
	};

	void update();
};

/// <summary>
/// ------------------------------------------- AI System --------------------------------------------
/// </summary>

class AiSystem 
{
	std::vector<Entity> m_entities;
public:
	void addEntity(Entity e)
	{
		m_entities.push_back(e);
	};

	void update()
	{
		std::cout << "AiSystem Update" << std::endl;
	}
};

/// <summary>
/// ------------------------------------------ Render System ----------------------------------------
/// </summary>
class RenderSystem 
{
	std::vector<Entity> m_entities;
public:
	void addEntity(Entity e)
	{
		m_entities.push_back(e);
	};

	void update();
	
	void setRenderer(SDL_Renderer* t_renderer)
	{
		m_renderer = t_renderer;
	}
	
	SDL_Renderer* getRenderer()
	{
		return m_renderer;
	};

private:
	SDL_Renderer* m_renderer = nullptr;
	SDL_Texture* m_texture;
	SDL_Surface* m_surface;
};

/// <summary>
/// --------------------------------------- Control System ----------------------------------------------
/// </summary>
class ControlSystem 
{
	std::vector<Entity> m_entities;
public:
	void addEntity(Entity e)
	{
		m_entities.push_back(e);
	};

	void update(SDL_Event& t_event);
	
};

#endif // !SYSTEM_H

