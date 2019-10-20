#ifndef ENTITY_H
#define ENTITY_H 

#include "Component.h"
#include <vector>
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"

class Component;
class System;

class Entity
{
	
public:
	Entity() {};

	void update()
	{

	};

	void addComponent(Component *t_c) 
	{
		m_components.push_back(t_c); 
	};
	
	void removeComponent(Component *t_c)
	{
		/// <summary>
		/// Not Implemented Yet
		/// </summary>
	};
	
	std::vector<Component *> getComponents() 
	{
		return m_components;
	};

	std::string getId()
	{
		return m_id;
	};

	SDL_Point getSize()
	{
		return m_imageSize;
	}

	void setImageSize(int t_x, int t_y)
	{
		m_imageSize.x = t_x;
		m_imageSize.y = t_y;
	}

	void setId(std::string t_id)
	{
		m_id = t_id;
	}

	void setRenderer(SDL_Renderer& t_r)
	{
		m_renderer = &t_r;
	}
	
	SDL_Renderer* getrenderer()
	{
		return m_renderer;
	}

	void setTextureName(const char * t_path)
	{
		m_imagePath = t_path;
	}

	const char* getImagePath()
	{
		return m_imagePath;
	}

private:

	const char * m_imagePath;

	SDL_Renderer* m_renderer = nullptr;

	SDL_Point m_imageSize{ 75,75};

	std::string m_id = "Entity";
	
	std::vector<Component *> m_components;
	
};

#endif // !ENTITY_H