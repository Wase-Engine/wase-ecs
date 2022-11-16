#pragma once

namespace wase::ecs
{
	template<typename T>
	bool Entity::hasComponent() const
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	template<typename T>
	T& Entity::getComponent() const
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	template<typename T>
	void Entity::addComponent()
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	template<typename T>
	void Entity::removeComponent()
	{
		throw std::exception("NOT IMPLEMENTED");
	}
}