#include <world.h>

namespace wase::ecs
{
	Entity* World::createEntity()
	{
		Entity* entity = m_EntityPool.createEntity();
		entity->m_World = this;

		m_SystemPool.onEntityCreated(entity);
		
		return entity;
	}

	Entity* World::getEntity(const Id entityId) const
	{
		return m_EntityPool.getEntity(entityId);
	}

	void World::destroyEntity(const Id entityId)
	{
		m_SystemPool.onEntityDestroyed(m_EntityPool.getEntity(entityId));
		m_EntityPool.destroyEntity(entityId);
	}

	void World::update(const float deltaTime)
	{
		m_SystemPool.update(deltaTime);
	}
}