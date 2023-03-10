#pragma once

#include <entity_pool.h>
#include <component_pool.h>
#include <system_pool.h>

namespace wase::ecs
{
	class World
	{
	public:
		/**
		 * Create a new entity.
		 * 
		 * @return The new entity.
		 */
		Entity* createEntity();

		/**
		 * Get an entity by its ID.
		 * 
		 * @param id The ID of the entity.
		 * @return The entity.
		 */
		Entity* getEntity(const Id entityId) const;

		/**
		 * Destroy an entity.
		 * 
		 * @param entity The entity to destroy.
		 */
		void destroyEntity(const Id entityId);

		/**
		 * Register a system with the system pool.
		 */
		template<typename T>
		void registerSystem();

		/**
		 * Update all registered systems.
		 * 
		 * @param deltaTime Delta time.
		 */
		void update(const float deltaTime);

	private:
		EntityPool m_EntityPool;
		ComponentPool m_ComponentPool;
		SystemPool m_SystemPool;

		friend class Entity;
	};
}

#include <world.inl>