#include <entity.h>

#include <world.h>

namespace wase::ecs
{
	Entity::Entity(const Id id)
		: m_ID(id)
	{
	}

	Id Entity::getId() const
	{
		return m_ID;
	}

	bool Entity::isEnabled() const
	{
		return m_Enabled;
	}
}