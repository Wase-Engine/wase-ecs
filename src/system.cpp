#include <system.h>

namespace wase::ecs
{
	void System::update(const float deltaTime)
	{

	}
	
	EntityFilter& System::getFilter()
	{
		return m_Filter;
	}

	void System::addEntity(Entity* entity)
	{
		if (entity->isEnabled())
			m_EnabledEntities.push_back(entity);
		else
			m_DisabledEntities.push_back(entity);
	}

	void System::removeEntity(Entity* entity)
	{
		m_EnabledEntities.erase(std::remove(m_EnabledEntities.begin(), m_EnabledEntities.end(), entity), m_EnabledEntities.end());
		m_DisabledEntities.erase(std::remove(m_DisabledEntities.begin(), m_DisabledEntities.end(), entity), m_DisabledEntities.end());
	}

	void System::enableEntity(Entity* entity)
	{
		m_DisabledEntities.erase(std::remove(m_DisabledEntities.begin(), m_DisabledEntities.end(), entity), m_DisabledEntities.end());
		m_EnabledEntities.push_back(entity);
	}

	void System::disableEntity(Entity* entity)
	{
		m_EnabledEntities.erase(std::remove(m_EnabledEntities.begin(), m_EnabledEntities.end(), entity), m_EnabledEntities.end());
		m_DisabledEntities.push_back(entity);
	}

	void System::checkEntity(Entity* entity)
	{
		if (m_Filter.matches(entity->getComponentMap()))
			if (std::find(m_EnabledEntities.begin(), m_EnabledEntities.end(), entity) == m_EnabledEntities.end() &&
				std::find(m_DisabledEntities.begin(), m_DisabledEntities.end(), entity) == m_DisabledEntities.end())
				addEntity(entity);
		else
			removeEntity(entity);
	}
}