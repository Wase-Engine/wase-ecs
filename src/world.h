#pragma once

#include <entity_pool.h>
#include <component_pool.h>

namespace wase::ecs
{
	class World
	{
	public:
		Entity& createEntity();

		Entity& getEntity(const Id entityId);

		void destroyEntity(const Id entityId);

	private:
		EntityPool m_EntityPool;
		ComponentPool m_ComponentPool;

		friend class Entity;
	};
}