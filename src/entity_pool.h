#pragma once

#include <vector>
#include <queue>
#include <cstdint>
#include <unordered_map>

#include <entity.h>

namespace wase::ecs
{
	class EntityPool
	{
	public:
		Entity& createEntity();

		std::vector<Entity*> getEntities();

		Entity& getEntity(const Id entityId);

		void destroyEntity(const Id entityId);

	private:
		std::vector<Entity> m_Entities;
		std::queue<Id> m_Ids;

		uint32_t m_NextId = 0;
	};
}