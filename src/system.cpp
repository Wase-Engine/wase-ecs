#include <algorithm>

#include <system.h>

namespace wase::ecs
{
	void System::update(const float deltaTime)
	{

	}

	void System::onEntityAdded(Entity* entity)
	{

	}

	void System::onEntityRemoved()
	{

	}

	void System::onEntityEnabled(Entity* entity)
	{

	}

	void System::onEntityDisabled(Entity* entity)
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

		onEntityAdded(entity);
	}

	void System::removeEntity(Entity* entity)
	{
		auto newEnd = std::remove_if(m_EnabledEntities.begin(), m_EnabledEntities.end(),
			[entity](Entity* e) { return e == entity; });
		
		m_EnabledEntities.erase(newEnd, m_EnabledEntities.end());
		onEntityRemoved();
	}

	void System::enableEntity(Entity* entity)
	{
		auto newEnd = std::remove(m_DisabledEntities.begin(), m_DisabledEntities.end(), entity);
		m_DisabledEntities.erase(newEnd, m_DisabledEntities.end());
		m_EnabledEntities.push_back(entity);
		onEntityEnabled(entity);
	}

	void System::disableEntity(Entity* entity)
	{
		auto newEnd = std::remove(m_EnabledEntities.begin(), m_EnabledEntities.end(), entity);
		m_EnabledEntities.erase(newEnd, m_EnabledEntities.end());
		m_DisabledEntities.push_back(entity);
		onEntityDisabled(entity);
	}

	void System::checkEntity(Entity* entity, const ComponentMap componentMap)
	{
		if (m_Filter.matches(componentMap))
			if (std::find(m_EnabledEntities.begin(), m_EnabledEntities.end(), entity) == m_EnabledEntities.end() &&
				std::find(m_DisabledEntities.begin(), m_DisabledEntities.end(), entity) == m_DisabledEntities.end())
				addEntity(entity);
		else
			removeEntity(entity);
	}
}