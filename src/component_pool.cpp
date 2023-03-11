#include <component_pool.h>

namespace wase::ecs
{
	ComponentMap ComponentPool::getComponentMap(const Id entityId) const
	{
		if (entityId >= m_ComponentMaps.size())
			return ComponentMap();
		
		return m_ComponentMaps[entityId];
	}

	void ComponentPool::onEntityDestroyed(const Id entityId)
	{
		if (entityId >= m_ComponentMaps.size())
			return;

		m_ComponentMaps[entityId] = ComponentMap();
		m_Components[entityId] = ComponentArray();
	}
}