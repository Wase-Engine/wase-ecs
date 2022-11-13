#include <entity.h>

namespace wase::ecs
{
	uint32_t Entity::getId() const
	{
		return m_Id;
	}

	std::string Entity::getName() const
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	void Entity::enable()
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	void Entity::disable()
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	bool Entity::isEnabled() const
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	Entity::operator uint32_t() const noexcept
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	bool Entity::operator==(const Entity& other) const
	{
		throw std::exception("NOT IMPLEMENTED");
	}
}