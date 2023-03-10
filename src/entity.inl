#pragma once

#include <entity.h>

namespace wase::ecs
{
	//template<typename T>
	//T& Entity::getComponent() const
	//{
	//	return m_World->m_ComponentPool.getComponent<T>(m_ID);
	//}

	//template<typename T, typename... Args>
	//T& Entity::addComponent(Args&&... args)
	//{
	//	m_World->m_ComponentPool.addComponent<T>(m_ID, std::make_shared<T>(std::forward<Args>(args)...));
	//	m_World->m_SystemPool.onEntityComponentMapChanged(this);

	//	return getComponent<T>();
	//}

	//template<typename T>
	//void Entity::removeComponent()
	//{
	//	m_World->m_ComponentPool.removeComponent<T>(m_ID);
	//	m_World->m_SystemPool.onEntityComponentMapChanged(this);
	//}

	//template<typename T>
	//bool Entity::hasComponent() const
	//{
	//	return m_World->m_ComponentPool.hasComponent<T>(m_ID);
	//}
}