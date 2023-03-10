#pragma once

#include <world.h>

namespace wase::ecs
{
	template<typename T>
	void World::registerSystem()
	{
		m_SystemPool.registerSystem<T>(m_EntityPool.getEntities());
	}
}