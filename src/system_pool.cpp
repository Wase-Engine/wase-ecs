#include <system_pool.h>

namespace wase::ecs
{
	void SystemPool::update(const float deltaTime) const
	{
		for (auto&[name, system] : m_Systems)
		{
			system->update(deltaTime);
		}
	}

	void SystemPool::onEntityCreated(Entity* entity, const ComponentMap componentMap) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(componentMap))
				system->addEntity(entity);
		}
	}

	void SystemPool::onEntityDestroyed(Entity* entity, const ComponentMap componentMap) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(componentMap))
				system->removeEntity(entity);
		}
	}

	void SystemPool::onEntityEnabled(Entity* entity, const ComponentMap componentMap) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(componentMap))
			{
				system->enableEntity(entity);
			}
		}
	}

	void SystemPool::onEntityDisabled(Entity* entity, const ComponentMap componentMap) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(componentMap))
			{
				system->disableEntity(entity);
			}
		}
	}

	void SystemPool::onEntityComponentMapChanged(Entity* entity, const ComponentMap componentMap) const
	{
		for (auto& [name, system] : m_Systems)
		{
			system->checkEntity(entity, componentMap);
		}
	}
}