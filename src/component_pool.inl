#pragma once

#include <component_pool.h>

namespace wase::ecs
{
	template<typename T>
	T& ComponentPool::addComponent(Entity entity, std::shared_ptr<T>&& component)
	{
		throw std::exception("NOT YET IMPLEMENTED");
	}

	template<typename T>
	T& ComponentPool::getComponent(Entity entity)
	{
		throw std::exception("NOT YET IMPLEMENTED");
	}

	template<typename T>
	bool ComponentPool::hasComponent(Entity entity)
	{
		throw std::exception("NOT YET IMPLEMENTED");
	}

	template<typename T>
	void ComponentPool::removeComponent(Entity entity)
	{
		throw std::exception("NOT YET IMPLEMENTED");
	}
}