#pragma once

#include <entity_pool.h>
#include <component_pool.h>
#include <system_pool.h>

namespace wase::ecs
{
	class World
	{
	public:
		Entity& createEntity();

		Entity& getEntity(const Id entityId);

		void destroyEntity(const Id entityId);

		template<typename T>
		void registerSystem();

		void update(const float deltaTime);

	private:
		EntityPool m_EntityPool;
		ComponentPool m_ComponentPool;
		SystemPool m_SystemPool;

		friend class Entity;
	};
}

#include <world.inl>