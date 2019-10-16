#ifndef ENTITY_H
#define ENTITY_H 

#include "Component.h"
#include <vector>
#include <iostream>
class Entity
{
	int id;
public:
	Entity() {};
	void addComponent(Component t_c) { m_components.push_back(t_c); };
	void removeComponent(Component t_c)
	{
		/// <summary>
		/// Not Implemented Yet
		/// </summary>
	};
	std::vector<Component> getComponents() 
	{
		return m_components;
	};

private:
	std::vector<Component> m_components;
	
};


#endif // !ENTITY_H