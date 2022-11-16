#include <entity_pool.h>

namespace wase::ecs
{
	EntityPool::EntityPool(const uint32_t maxAmountEntities)
	{
		for (uint32_t i = 0; i < maxAmountEntities; i++)
			m_Ids.push(i);
	}

	Entity EntityPool::createEntity()
	{
		if (m_Ids.empty())
			throw std::exception("Entity pool is full");

		uint32_t id = m_Ids.front();
		m_Ids.pop();
		
		m_Size++;
		
		return Entity(id);
	}

	void EntityPool::destroyEntity(Entity entity)
	{
		m_Ids.push(entity.getId());
		m_Size--;
	}

	uint32_t EntityPool::getSize() const
	{
		return m_Size;
	}
}