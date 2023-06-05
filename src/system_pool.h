#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <memory>

#include <system.h>
#include <entity.h>
#include <component.h>

namespace wase::ecs
{
	class SystemPool
	{
	public:
		/**
		 * Register a system with the system pool.
		 * 
		 * @param entities Entities to register the system with.
		 * @param componentMaps Component maps of the entities.
		 * @param componentPool Component pool.
		 */
		template<typename T, typename... TArgs>
		void registerSystem(std::vector<Entity*> entities, std::vector<ComponentMap> componentMaps, ComponentPool* componentPool, TArgs&&... args);

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
		 * @param componentMap The component map of the entity.
		 */
		void onEntityCreated(Entity* entity, const ComponentMap componentMap) const;

		/**
		 * Update all registered systems when an entity is destroyed.
		 * 
		 * @param entity The entity that has been destroyed.
		 * @param componentMap The component map of the entity.
		 */
		void onEntityDestroyed(Entity* entity, const ComponentMap componentMap) const;

		/**
		 * Update all registered systems when an entity is enabled.
		 * 
		 * @param entity The entity that has been enabled.
		 * @param componentMap The component map of the entity.
		 */
		void onEntityEnabled(Entity* entity, const ComponentMap componentMap) const;

		/**
		 * Update all registered systems when an entity is disabled.
		 * 
		 * @param entity The entity that has been disabled.
		 * @param componentMap The component map of the entity.
		 */
		void onEntityDisabled(Entity* entity, const ComponentMap componentMap) const;

		/**
		 * Update all registered systems when a component has been added/removed to an entity.
		 * 
		 * @param entity The entity that has been modified.
		 * @param componentMap The component map of the entity.
		 */
		void onEntityComponentMapChanged(Entity* entity, const ComponentMap componentMap) const;

	private:
		std::unordered_map<std::string, std::shared_ptr<System>> m_Systems;
	};
}

#include <system_pool.inl>