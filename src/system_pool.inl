#pragma once

#include <system_pool.h>

namespace wase::ecs
{
	template<typename T>
	void SystemPool::registerSystem(std::vector<Entity*> entities)
	{
		const std::string name = typeid(T).name();

		m_Systems.insert({ name, std::make_shared<T>() });
		
		for (Entity* entity : entities)
		{
			if (m_Systems[name]->getFilter().matches(entity->getComponentMap()))
				if (entity->isEnabled())
					m_Systems[name]->m_EnabledEntities.push_back(entity);
				else
					m_Systems[name]->m_DisabledEntities.push_back(entity);
		}
	}
}