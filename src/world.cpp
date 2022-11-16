#include <world.h>

namespace wase::ecs
{
	World::World(const uint32_t maxAmountEntities)
		: m_EntityPool(maxAmountEntities)
	{

	}

	Entity World::createEntity()
	{
		return m_EntityPool.createEntity();
	}

	Entity World::createEntity(const std::string& name)
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	Entity World::getEntityById(const uint32_t id)
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	Entity World::getEntityByName(const std::string& name)
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	std::string World::getEntityNameById(const uint32_t id)
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	void World::enableEntity(const uint32_t id)
	{
		throw std::exception("NOT IMPLEMENTED");
	}

	void World::disableEntity(const uint32_t id)
	{
		throw std::exception("NOT IMPLEMENTED");
	}
}