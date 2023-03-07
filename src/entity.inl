#pragma once

#include <entity.h>

namespace wase::ecs
{
	template<typename T>
	T& Entity::getComponent()
	{
		return m_World->m_ComponentPool.getComponent<T>(m_ID);
	}

	template<typename T, typename... Args>
	T& Entity::addComponent(Args&&... args)
	{
		m_World->m_ComponentPool.addComponent<T>(m_ID, std::make_shared<T>(std::forward<Args>(args)...));

		return getComponent<T>();
	}

	template<typename T>
	void Entity::removeComponent()
	{
		m_World->m_ComponentPool.removeComponent<T>(m_ID);
	}

	template<typename T>
	bool Entity::hasComponent()
	{
		return m_World->m_ComponentPool.hasComponent<T>(m_ID);
	}
}