#pragma once

#include <component_pool.h>

namespace wase::ecs
{
	template<typename T>
	T& ComponentPool::getComponent(const Id entityId)
	{
		return *std::static_pointer_cast<T>(m_Components[entityId][getComponentTypeId<T>()]);
	}

	template<typename T>
	T& ComponentPool::addComponent(const Id entityId, std::shared_ptr<T>&& component)
	{
		const size_t typeId = getComponentTypeId<T>();

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
		const size_t typeId = getComponentTypeId<T>();

		m_Components[entityId][typeId] = nullptr;
		m_ComponentMaps[entityId].reset(typeId);
	}

	template<typename T>
	bool ComponentPool::hasComponent(const Id entityId)
	{
		if (entityId >= m_ComponentMaps.size())
			return false;
		
		return m_ComponentMaps[entityId].test(getComponentTypeId<T>());
	}

	template<typename T>
	size_t ComponentPool::getComponentTypeId()
	{
		const std::string typeName = typeid(T).name();

		if (componentTypeIds.size() >= MAX_COMPONENTS)
			throw std::runtime_error("Too many components");

		if (componentTypeIds.find(typeName) == componentTypeIds.end())
			componentTypeIds[typeName] = componentTypeIds.size();

		return componentTypeIds[typeName];
	}
}