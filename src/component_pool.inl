#pragma once

#include <component_pool.h>
#include <type_id.h>

namespace wase::ecs
{
	template<typename T>
	T& ComponentPool::getComponent(const Id entityId)
	{
		return *std::static_pointer_cast<T>(m_Components[entityId][TypeID::getTypeID<T>()]);
	}

	template<typename T>
	T& ComponentPool::addComponent(const Id entityId, std::shared_ptr<T>&& component)
	{
		const size_t typeId = TypeID::getTypeID<T>();

		if (m_Components.size() <= entityId)
		{
			m_Components.resize(entityId + 1);
			m_ComponentMaps.resize(entityId + 1);
		}
		
		m_Components[entityId][typeId] = std::move(component);
		m_ComponentMaps[entityId].set(typeId);

		return getComponent<T>(entityId);
	}

	template<typename T>
	void ComponentPool::removeComponent(const Id entityId)
	{
		const size_t typeId = TypeID::getTypeID<T>();

		m_Components[entityId][typeId] = nullptr;
		m_ComponentMaps[entityId].reset(typeId);
	}

	template<typename T>
	bool ComponentPool::hasComponent(const Id entityId)
	{
		if (entityId >= m_ComponentMaps.size())
			return false;
		
		return m_ComponentMaps[entityId].test(TypeID::getTypeID<T>());
	}
}