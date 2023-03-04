#include <entity_pool.h>

namespace wase::ecs
{
	Entity EntityPool::createEntity()
	{
		if (m_Ids.size() <= 0)
			m_Ids.push(m_NextId++);

		uint32_t id = m_Ids.front();
		m_Ids.pop();

		extend(id + 1);
		
		m_Size++;
		
		m_Entities[id].entity = id;
		
		return id;
	}

	Entity EntityPool::createEntity(const std::string& name)
	{
		if (m_Names.count(name))
			throw std::exception("Entity name already exists");

		Entity entity = createEntity();

		m_Entities[entity].name = name;
		m_Names[name] = entity;
		
		return entity;
	}

	std::string EntityPool::getEntityName(const uint32_t id) const
	{
		return m_Entities[id].name;
	}

	Entity EntityPool::getEntityByName(const std::string& name) const
	{
		return m_Names.count(name) ? m_Names.at(name) : -1;
	}

	void EntityPool::disableEntity(const Entity entity)
	{
		m_Entities[entity].enabled = false;
	}

	void EntityPool::enableEntity(const Entity entity)
	{
		m_Entities[entity].enabled = true;
	}

	bool EntityPool::isEnabled(const Entity entity) const
	{
		return m_Entities[entity].enabled;
	}

	void EntityPool::destroyEntity(const Entity id)
	{
		m_Names.erase(getEntityName(id));
		m_Entities[id] = EntityHolder();
		m_Ids.push(id);
		m_Size--;
	}

	uint32_t EntityPool::getSize() const
	{
		return m_Size;
	}

	void EntityPool::extend(const uint32_t size)
	{
		if (size > m_Entities.size())
			m_Entities.resize(size);
	}
}