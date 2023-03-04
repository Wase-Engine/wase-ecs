#include <world.h>

namespace wase::ecs
{	
	Entity World::createEntity()
	{
		return m_EntityPool.createEntity();
	}

	Entity World::createEntity(const std::string& name)
	{
		return m_EntityPool.createEntity(name);
	}

	std::string World::getEntityName(const uint32_t id) const
	{
		return m_EntityPool.getEntityName(id);
	}

	Entity World::getEntityByName(const std::string& name) const
	{
		return m_EntityPool.getEntityByName(name);
	}

	void World::disableEntity(const Entity entity)
	{
		m_EntityPool.disableEntity(entity);
	}

	void World::enableEntity(const Entity entity)
	{
		m_EntityPool.enableEntity(entity);
	}

	bool World::isEnabled(const Entity entity) const
	{
		return m_EntityPool.isEnabled(entity);
	}

	void World::destroyEntity(const Entity id)
	{
		m_EntityPool.destroyEntity(id);
	}

	uint32_t World::getAmountOfEntities() const
	{
		return m_EntityPool.getSize();
	}
}