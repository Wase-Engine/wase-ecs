#include <entity.h>

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

	void Entity::enable()
	{
		m_Enabled = true;
	}

	void Entity::disable()
	{
		m_Enabled = false;
	}

	bool Entity::isEnabled() const
	{
		return m_Enabled;
	}
}