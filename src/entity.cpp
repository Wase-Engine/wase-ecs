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

	ComponentMap Entity::getComponentMap() const
	{
		return m_World->m_ComponentPool.getComponentMap(m_ID);
	}

	void Entity::enable()
	{
		m_Enabled = true;
		m_World->m_SystemPool.onEntityEnabled(this);
	}

	void Entity::disable()
	{
		m_Enabled = false;
		m_World->m_SystemPool.onEntityDisabled(this);
	}

	bool Entity::isEnabled() const
	{
		return m_Enabled;
	}
}