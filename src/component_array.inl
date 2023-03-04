#pragma once

#include <component_array.h>

#include <stdexcept>

namespace wase::ecs
{
	template<typename T>
	void ComponentArray<T>::insert(const Entity entity, T component)
	{
		m_Components[entity] = component;
		m_Size++;
	}
	
	template<typename T>
	void ComponentArray<T>::remove(const Entity entity)
	{
		m_Components.erase(entity);
		m_Size--;
	}

	template<typename T>
	bool ComponentArray<T>::hasEntity(const Entity entity) const
	{
		return m_Components.find(entity) != m_Components.end();
	}

	template<typename T>
	T& ComponentArray<T>::getData(const Entity entity) const
	{
		if (m_Components.find(entity) == m_Components.end())
			throw std::logic_error("There is no component of this type belonging to the entity.");

		return m_Components[entity];
	}

	template<typename T>
	uint32_t ComponentArray<T>::getSize() const
	{
		return m_Size;
	}
}