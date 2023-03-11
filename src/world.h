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
		 * Enable an entity.
		 * 
		 * @param entity The entity to enable.
		 */
		void enableEntity(const Id entityId);

		/**
		 * Disable an entity.
		 * 
		 * @param entity The entity to disable.
		 */
		void disableEntity(const Id entityId);

		/**
		 * Get a component from an entity.
		 * 
		 * @param entityId The ID of the entity.
		 * @return The component.
		 */
		template<typename T>
		T& getComponent(const Id entityId) const;

		/**
		 * Add a component to an entity.
		 * 
		 * @param entityId The ID of the entity.
		 * @param component The component to add.
		 * @return The component.
		 */
		template<typename T, typename... Args>
		T& addComponent(const Id entityId, Args&&... args);

		/**
		 * Remove a component from an entity.
		 * 
		 * @param entityId The ID of the entity.
		 */
		template<typename T>
		void removeComponent(const Id entityId);

		/**
		 * Check if an entity has a component.
		 * 
		 * @param entityId The ID of the entity.
		 * @return True if the entity has the component.
		 */
		template<typename T>
		bool hasComponent(const Id entityId) const;

		/**
		 * Get the component map of an entity.
		 * 
		 * @param entityId The ID of the entity.
		 * @return The component map.
		 */
		ComponentMap getComponentMap(const Id entityId) const;

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