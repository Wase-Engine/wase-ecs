#include <entity_pool.h>

namespace wase::ecs
{
	Entity& EntityPool::createEntity()
	{
		if (m_Ids.size() <= 0)
			m_Ids.push(m_NextId++);

		const auto id = m_Ids.front();
		m_Ids.pop();

		if (m_Entities.size() <= id)
			m_Entities.resize(id + 1);

		m_Entities[id] = Entity(id);

		return m_Entities[id];
	}

	std::vector<Entity*> EntityPool::getEntities()
	{
		std::vector<Entity*> entities;

		for (auto& entity : m_Entities)
			entities.push_back(&entity);

		return entities;
	}

	Entity& EntityPool::getEntity(const Id entityId)
	{
		return m_Entities.at(entityId);
	}

	void EntityPool::destroyEntity(const Id entityId)
	{
		m_Entities[entityId] = Entity(-1);
		m_Ids.push(entityId);
	}
}