#pragma once

#include <world.h>

namespace wase::ecs
{
	template<typename T, typename... TArgs>
	void World::registerSystem(TArgs&&... args)
	{
		std::vector<Entity*> entities, entitiesPool;
		std::vector<ComponentMap> componentMaps;

		entitiesPool = m_EntityPool.getEntities();

		for (int i = 0; i < entitiesPool.size(); i++)
		{
			entities.push_back(entitiesPool[i]);
			componentMaps.push_back(m_ComponentPool.getComponentMap(entitiesPool[i]->getId()));
		}

		m_SystemPool.registerSystem<T>(entities, componentMaps, &m_ComponentPool, T(std::forward<TArgs>(args)...));
	}

	template<typename T>
	T& World::getComponent(const Id entityId) const
	{
		return m_ComponentPool.getComponent<T>(entityId);
	}

	template<typename T, typename... Args>
	T& World::addComponent(const Id entityId, Args&&... args)
	{
		m_ComponentPool.addComponent<T>(entityId, std::make_shared<T>(std::forward<Args>(args)...));
		m_SystemPool.onEntityComponentMapChanged(getEntity(entityId), getComponentMap(entityId));

		return getComponent<T>(entityId);
	}

	template<typename T>
	void World::removeComponent(const Id entityId)
	{
		m_ComponentPool.removeComponent<T>(entityId);
		m_SystemPool.onEntityComponentMapChanged(getEntity(entityId), getComponentMap(entityId));
	}

	template<typename T>
	bool World::hasComponent(const Id entityId) const
	{
		return m_ComponentPool.hasComponent<T>(entityId);
	}
}