#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include <unordered_map>
#include <memory>

#include <entity.h>

namespace wase::ecs
{
	class EntityPool
	{
	public:
		/**
		 * Create a new entity.
		 * 
		 * @return The new entity.
		 */
		Entity* createEntity();

		/**
		 * Get all entities.
		 * 
		 * @return A vector of all entities.
		 */
		std::vector<Entity*> getEntities() const;

		/**
		 * Get an entity by its ID.
		 * 
		 * @param id The ID of the entity.
		 * @return The entity with the given ID.
		 */
		Entity* getEntity(const Id entityId) const;

		/**
		 * Destroy an entity.
		 * 
		 * @param entity The entity to destroy.
		 */
		void destroyEntity(const Id entityId);

	private:
		std::vector<std::shared_ptr<Entity>> m_Entities;
		std::queue<Id> m_Ids;

		uint32_t m_NextId = 0;
	};
}