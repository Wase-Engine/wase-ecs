#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

#include <system.h>
#include <entity.h>

namespace wase::ecs
{
	class SystemPool
	{
	public:
		template<typename T>
		void registerSystem(std::vector<Entity*> entities);

		void update(const float deltaTime) const;

		void onEntityCreated(Entity* entity) const;

		void onEntityDestroyed(Entity* entity) const;

		void onEntityEnabled(Entity* entity) const;

		void onEntityDisabled(Entity* entity) const;

		void onEntityComponentMapChanged(Entity* entity) const;

	private:
		std::unordered_map<std::string, std::shared_ptr<System>> m_Systems;
	};
}

#include <system_pool.inl>