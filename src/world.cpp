#include <world.h>

namespace wase::ecs
{
	Entity& World::createEntity()
	{
		Entity& entity = m_EntityPool.createEntity();
		entity.m_World = this;
		
		return entity;
	}

	Entity& World::getEntity(const Id entityId)
	{
		return m_EntityPool.getEntity(entityId);
	}

	void World::destroyEntity(const Id entityId)
	{
		m_EntityPool.destroyEntity(entityId);
	}
}