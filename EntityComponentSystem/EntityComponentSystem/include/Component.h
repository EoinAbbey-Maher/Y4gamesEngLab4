#ifndef COMPONENT_H
#define COMPONENT_H

#include "Entity.h"
#include "System.h"
#include "SDL.h"

enum ComponentType
{
	HEALTH,
	INPUT,
	POSITION
};

class Entity;
class System;

class Component
{
public:
	Component() {};
	virtual ~Component() {};

	virtual const ComponentType getType() = 0;

};

/// <summary>
///  ------------------------------------ Health Component ---------------------- 
/// </summary>
class HealthComponent : public Component
{
public :	
	HealthComponent() :
		m_health(100) {};

	void setHealth(int t_health)
	{
		m_health = t_health;
	}

	const ComponentType getType() {
		return TYPE;
	}
	
	int getHealth() { return m_health; }
private:
	const ComponentType TYPE{ ComponentType::HEALTH };

	int m_health;
};

/// <summary>
///  --------------------------------------------- Position Component ---------------------
/// </summary>

class PositionComponent : public Component
{
public:
	PositionComponent() {};
	
	PositionComponent(int x, int y) 
	{
		m_position.x = x;
		m_position.y = y;
	};

	void setPosition(SDL_Point t_position)
	{
		m_position = t_position;
	}

	SDL_Point getPosition()
	{
		return m_position;
	}

	const ComponentType getType() {
		return TYPE;
	}
private:
	const ComponentType TYPE{ ComponentType::POSITION };
	SDL_Point m_position{ 0,0 };
};

/// <summary>
/// -------------------------------------- Input Component ---------------------------------
/// </summary>
class InputComponent : public Component
{
public:
	InputComponent() {};

	const ComponentType getType() {
		return TYPE;
	}
private:
	const ComponentType TYPE{ ComponentType::INPUT };
};

#endif // !COMPONENT_H

