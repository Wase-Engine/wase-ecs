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

	void SystemPool::onEntityCreated(Entity* entity) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(entity->getComponentMap()))
				system->addEntity(entity);
		}
	}

	void SystemPool::onEntityDestroyed(Entity* entity) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(entity->getComponentMap()))
				system->removeEntity(entity);
		}
	}

	void SystemPool::onEntityEnabled(Entity* entity) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(entity->getComponentMap()))
			{
				system->enableEntity(entity);
			}
		}
	}

	void SystemPool::onEntityDisabled(Entity* entity) const
	{
		for (auto& [name, system] : m_Systems)
		{
			if (system->getFilter().matches(entity->getComponentMap()))
			{
				system->disableEntity(entity);
			}
		}
	}

	void SystemPool::onEntityComponentMapChanged(Entity* entity) const
	{
		for (auto& [name, system] : m_Systems)
		{
			system->checkEntity(entity);
		}
	}
}