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
		/**
		 * Register a system with the system pool.
		 * 
		 * @param entities Entities to register the system with.
		 */
		template<typename T>
		void registerSystem(std::vector<Entity*> entities);

		/**
		 * Update all registered systems.
		 * 
		 * @param deltaTime Delta time.
		 */
		void update(const float deltaTime) const;

		/**
		 * Update all registered systems when a new entity is created.
		 * 
		 * @param entity The entity that has been created.
		 */
		void onEntityCreated(Entity* entity) const;

		/**
		 * Update all registered systems when an entity is destroyed.
		 * 
		 * @param entity The entity that has been destroyed.
		 */
		void onEntityDestroyed(Entity* entity) const;

		/**
		 * Update all registered systems when an entity is enabled.
		 * 
		 * @param entity The entity that has been enabled.
		 */
		void onEntityEnabled(Entity* entity) const;

		/**
		 * Update all registered systems when an entity is disabled.
		 * 
		 * @param entity The entity that has been disabled.
		 */
		void onEntityDisabled(Entity* entity) const;

		/**
		 * Update all registered systems when a component has been added/removed to an entity.
		 * 
		 * @param entity The entity that has been modified.
		 */
		void onEntityComponentMapChanged(Entity* entity) const;

	private:
		std::unordered_map<std::string, std::shared_ptr<System>> m_Systems;
	};
}

#include <system_pool.inl>