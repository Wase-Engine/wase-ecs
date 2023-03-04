#pragma once

#include <cstdint>
#include <queue>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

namespace wase::ecs
{
	using Entity = uint32_t;

	struct EntityHolder
	{
		Entity entity = -1;
		std::string name;
		bool enabled = true;
	};

	class EntityPool
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
		 * Get the amount of entities in the pool.
		 */
		uint32_t getSize() const;

	private:
		/**
		 * Extend the entity pool.
		 *
		 * @param amount The amount of entities to add.
		 */
		void extend(const uint32_t size);

		std::vector<EntityHolder> m_Entities;
		std::unordered_map<std::string, Entity> m_Names;
		std::queue<uint32_t> m_Ids;
		
		uint32_t m_NextId = 0;
		uint32_t m_Size = 0;
	};
}