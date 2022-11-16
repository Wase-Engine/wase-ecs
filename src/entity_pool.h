#pragma once

#include <cstdint>
#include <queue>

#include <entity.h>

namespace wase::ecs
{
	class EntityPool
	{
	public:
		/**
		 * Create a new entity pool
		 * 
		 * @param capacity: the maximum capacity of the entity pool
		 */
		EntityPool(const uint32_t maxAmountEntities);

		/**
		 * Create a new entity.
		 * 
		 * @return The new entity.
		 */
		Entity createEntity();

		/**
		 * Destroy an entity.
		 *
		 * @param entity The entity to destroy.
		 */
		void destroyEntity(Entity entity);

		/**
		 * Get the amount of entities in the pool.
		 */
		uint32_t getSize() const;

	private:
		std::queue<uint32_t> m_Ids;
		
		uint32_t m_NextId = 0;
		uint32_t m_Size = 0;
	};
}