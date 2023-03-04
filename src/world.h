#pragma once

#include <string>
#include <cstdint>

#include <system.h>
#include <entity_pool.h>
#include <component_pool.h>

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
		Entity createEntity();

		/**
		 * Create a new entity with a name.
		 *
		 * @param name: the name of the entity
		 * @return The new entity.
		 */
		Entity createEntity(const std::string& name);

		/**
		 * Get the entity name by its id
		 *
		 * @param id: the entity id
		 * @return The name of the entity
		 */
		std::string getEntityName(const uint32_t id) const;

		/**
		 * Get an entity by name
		 *
		 * @param name: the name of the entity
		 * @return The entity or -1 if the name doesn't match any entity
		 */
		Entity getEntityByName(const std::string& name) const;

		/**
		 * Disable an entity
		 *
		 * @param id: the entity id
		 */
		void disableEntity(const Entity entity);

		/**
		 * Enable an entity
		 *
		 * @param id: the entity id
		 */
		void enableEntity(const Entity entity);

		/**
		 * Check if an entity is enabled
		 *
		 * @param id: the entity id
		 * @return true if the entity is enabled
		 */
		bool isEnabled(const Entity entity) const;

		/**
		 * Destroy an entity.
		 *
		 * @param id: The entity id
		 */
		void destroyEntity(const Entity id);

		
		/**
		 * Get the amount of entities in the world
		 * 
		 * @return The amount of entities
		 */
		uint32_t getAmountOfEntities() const;

		/**
		 * Registers a component type with the component pool.
		 */
		template<typename T>
		void registerComponent();

		/**
		 * Add a component to an entity
		 *
		 * @param entity: the entity to add the component to
		 * @param component: the component to add
		 * @return The component
		 */
		template<typename T>
		void addComponent(Entity entity, T component);

		/**
		 * Check if an entity has a component
		 *
		 * @param entity: the entity to check
		 * @return True if the entity has the component
		 */
		template<typename T>
		bool hasComponent(Entity entity);

		/**
		 * Get a component from an entity
		 *
		 * @param entity: the entity to get the component from
		 * @return The component
		 */
		template<typename T>
		T& getComponent(Entity entity);

		/**
		 * Remove a component from an entity
		 *
		 * @param entity: the entity to remove the component from
		 */
		template<typename T>
		void removeComponent(Entity entity);

	private:
		EntityPool m_EntityPool;
		ComponentPool m_ComponentPool;
	};
}