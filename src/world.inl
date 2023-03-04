#pragma once

#include <world.h>

namespace wase::ecs
{
	template<typename T>
	void World::registerComponent()
	{
		m_ComponentPool.registerComponent<T>();
	}

	template<typename T>
	void World::addComponent(Entity entity, T component)
	{
		m_ComponentPool.addComponent<T>(entity, component);
	}

	template<typename T>
	bool World::hasComponent(Entity entity)
	{
		return m_ComponentPool.hasComponent<T>(entity);
	}

	template<typename T>
	T& World::getComponent(Entity entity)
	{
		return m_ComponentPool.getComponent<T>(entity);
	}

	template<typename T>
	void World::removeComponent(Entity entity)
	{
		m_ComponentPool.removeComponent<T>(entity);
	}
}