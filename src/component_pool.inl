#pragma once

#include <component_pool.h>

#include <stdexcept>

namespace wase::ecs
{
	template<typename T>
	void wase::ecs::ComponentPool::registerComponent()
	{
		std::string name = typeid(T).name();

		if (m_ComponentArrays.find(name) != m_ComponentArrays.end())
			throw std::logic_error("Component is already registered.");

		m_ComponentArrays.insert({ name, std::make_shared<ComponentArray<T>>() });
	}

	template<typename T>
	void ComponentPool::addComponent(Entity entity, T component)
	{
		getComponentArray<T>()->insert(entity, component);
	}

	template<typename T>
	T& ComponentPool::getComponent(Entity entity)
	{
		return getComponentArray<T>()->getData(entity);
	}

	template<typename T>
	bool ComponentPool::hasComponent(Entity entity)
	{
		return getComponentArray<T>()->hasEntity(entity);
	}

	template<typename T>
	void ComponentPool::removeComponent(Entity entity)
	{
		getComponentArray<T>()->remove(entity);
	}

	template<typename T>
	std::shared_ptr<ComponentArray<T>> ComponentPool::getComponentArray()
	{
		std::string name = typeid(T).name();

		if (m_ComponentArrays.find(name) == m_ComponentArrays.end())
			throw std::logic_error("Component is not registered.");

		return std::static_pointer_cast<ComponentArray<T>>(m_ComponentArrays[name]);
	}
}