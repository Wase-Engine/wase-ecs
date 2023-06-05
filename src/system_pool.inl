#pragma once

#include <system_pool.h>

namespace wase::ecs
{
	template<typename T, typename... TArgs>
	void SystemPool::registerSystem(std::vector<Entity*> entities, std::vector<ComponentMap> componentMaps, ComponentPool* componentPool, TArgs&&... args)
	{
		const std::string name = typeid(T).name();

		m_Systems.insert({ name, std::make_shared<T>(T(std::forward<TArgs>(args)...)) });

		for (size_t i = 0; i < entities.size(); i++)
		{
			if (m_Systems[name]->getFilter().matches(componentMaps[i]))
				if (entities[i]->isEnabled())
					m_Systems[name]->m_EnabledEntities.push_back(entities[i]);
				else
					m_Systems[name]->m_DisabledEntities.push_back(entities[i]);
		}

		m_Systems[name]->m_ComponentPool = componentPool;
	}
}