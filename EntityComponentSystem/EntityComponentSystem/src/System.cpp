#include "System.h"

/// <summary>
/// --------------------------------------------- Health System ------------------------------------
/// </summary>
void HealthSystem::update()
{
	for (int i = 0; i < m_entities.size(); i++)
	{
		std::vector<Component*> components = m_entities[i].getComponents();
		{
			for (int j = 0; j < components.size(); j++)
			{
				if (components[j]->getType() == ComponentType::HEALTH)
				{
					HealthComponent* healthcomp = static_cast<HealthComponent *> (components[j]);

					if (healthcomp->getHealth() > 0)
					{
						//std::cout << m_entities[i].getId() << " has " << healthcomp->getHealth() << " Health Left" << std::endl;
						//std::cout << std::endl;
					}
					else
					{
						//std::cout << "Fam Dead" << std::endl;
					}

					healthcomp = nullptr;
				}
				components.clear();
			}
			
		}
		
	}
}

/// <summary>
/// ------------------------------------------ Render System -------------------------------
/// </summary>
void RenderSystem::update()
{

	for (int i = 0; i < m_entities.size(); i++)
	{
		
		std::vector<Component*> components = m_entities[i].getComponents();
		{
			for (int j = 0; j < components.size(); j++)
			{
				if (components[j]->getType() == ComponentType::POSITION)
				{
					PositionComponent* poscomp = static_cast<PositionComponent*> (components[j]);

						m_surface = SDL_LoadBMP(m_entities[i].getImagePath());
						m_texture = SDL_CreateTextureFromSurface(m_renderer, m_surface);

						if (m_texture!= nullptr && m_renderer != nullptr)
						{
							SDL_Rect drawPosition;
							drawPosition.x = poscomp->getPosition().x;
							drawPosition.y = poscomp->getPosition().y;
							drawPosition.h = m_entities[i].getSize().y;
							drawPosition.w = m_entities[i].getSize().x;


							SDL_RenderCopy(m_renderer, m_texture, NULL, &drawPosition);
						}
					
					poscomp = nullptr;
				}
				
			}
			components.clear();
		}

	}

}
/// <summary>
/// ----------------------------------------- Control System -----------------------------------
/// </summary>

void ControlSystem::update(SDL_Event& t_event)
{
	SDL_Event  event = t_event;
	for (int i = 0; i < m_entities.size(); i++)
	{

		std::vector<Component*> components = m_entities[i].getComponents();
		{
			for (int j = 0; j < components.size(); j++)
			{
				if (components[j]->getType() == ComponentType::INPUT)
				{
					for (int k = 0; k < components.size(); k++)
					{
						if (components[k]->getType() == ComponentType::POSITION)
						{
							PositionComponent* poscomp = static_cast<PositionComponent*> (components[k]);

							SDL_Point newPos{ 0,0 };
							switch (event.key.keysym.sym)
							{
							case SDLK_UP:
								std::cout << m_entities[i].getId() << " Move Up" << std::endl;
								newPos.x = poscomp->getPosition().x;
								newPos.y = poscomp->getPosition().y - 1;
								poscomp->setPosition(newPos);
								break;

							case SDLK_DOWN:
								std::cout << m_entities[i].getId() << " Move Down" << std::endl;
								newPos.x = poscomp->getPosition().x;
								newPos.y = poscomp->getPosition().y + 1;
								poscomp->setPosition(newPos);
								break;

							case SDLK_LEFT:
								std::cout << m_entities[i].getId() << " Move Left" << std::endl;
								newPos.x = poscomp->getPosition().x - 1;
								newPos.y = poscomp->getPosition().y;
								poscomp->setPosition(newPos);
								break;

							case SDLK_RIGHT:
								std::cout << m_entities[i].getId() << " Move Right" << std::endl;
								newPos.x = poscomp->getPosition().x + 1;
								newPos.y = poscomp->getPosition().y;
								poscomp->setPosition(newPos);
								break;

							default:
								break;
							}
							poscomp = nullptr;
						}
					}

					
				}

			}
			components.clear();
		}

	}

	

	
}
