#pragma once

#include <string>
#include <cstdint>

#include <system.h>
#include <entity.h>
#include <entity_pool.h>

namespace wase::ecs
{
	class World
	{
	public:
		/**
		 * Create a new world.
		 * 
		 * @param maxAmountEntities: the maximum amount of entities that can be created in this world.
		 */
		World(const uint32_t maxAmountEntities);

		/**
		 * Create an entity
		 * 
		 * @return the entity that has been created
		 */
		Entity createEntity();

		/**
		 * Create an entity
		 * 
		 * @param name: the name of the entity
		 * @return the entity that has been created
		 */
		Entity createEntity(const std::string& name);

		/**
		 * Get an entity by its ID
		 *
		 * @param id: the ID of the entity
		 * @return the entity with the specified ID
		 */
		Entity getEntityById(const uint32_t id);

		/**
		 * Get an entity by its name
		 *
		 * @param name: the name of the entity
		 * @return the entity with the specified name
		 */
		Entity getEntityByName(const std::string& name);

		/**
		 * Get the name of an entity by its ID
		 *
		 * @param id: the ID of the entity
		 * @return the name of the entity with the specified ID
		 */
		std::string getEntityNameById(const uint32_t id);

		/**
		 * Enable an entity
		 *
		 * @param entity: the entity to enable
		 */
		void enableEntity(const uint32_t id);

		/**
		 * Disable an entity
		 *
		 * @param entity: the entity to disable
		 */
		void disableEntity(const uint32_t id);

	private:
		EntityPool m_EntityPool;
	};
}