#ifndef COMPONENT_H
#define COMPONENT_H


class Component
{
};

class HealthComponent : public Component
{
public :
	HealthComponent() : m_health(100) {};

	int getHealth() { return m_health; }
private:
	int m_health;
};

#endif // !COMPONENT_H

