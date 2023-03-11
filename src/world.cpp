#include <world.h>

namespace wase::ecs
{
	Entity* World::createEntity()
	{
		Entity* entity = m_EntityPool.createEntity();

		m_SystemPool.onEntityCreated(entity, getComponentMap(entity->getId()));
		
		return entity;
	}

	Entity* World::getEntity(const Id entityId) const
	{
		return m_EntityPool.getEntity(entityId);
	}

	void World::destroyEntity(const Id entityId)
	{
		m_SystemPool.onEntityDestroyed(m_EntityPool.getEntity(entityId), getComponentMap(entityId));
		m_ComponentPool.onEntityDestroyed(entityId);
		m_EntityPool.destroyEntity(entityId);
	}

	void World::update(const float deltaTime)
	{
		m_SystemPool.update(deltaTime);
	}

	void World::enableEntity(const Id entityId)
	{
		Entity* entity = m_EntityPool.getEntity(entityId);
		entity->m_Enabled = true;
		m_SystemPool.onEntityEnabled(entity, getComponentMap(entityId));
	}

	void World::disableEntity(const Id entityId)
	{
		Entity* entity = m_EntityPool.getEntity(entityId);
		entity->m_Enabled = false;
		m_SystemPool.onEntityDisabled(entity, getComponentMap(entityId));
	}

	ComponentMap World::getComponentMap(const Id entityId) const
	{
		return m_ComponentPool.getComponentMap(entityId);
	}
}