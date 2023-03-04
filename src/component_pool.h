#pragma once

#include <cstdint>
#include <memory>
#include <unordered_map>
#include <string>

#include <component.h>
#include <component_array.h>

namespace wase::ecs
{
	using Entity = uint32_t;
	
	class ComponentPool
	{
	public:
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
		std::unordered_map<std::string, std::shared_ptr<IComponentArray>> m_ComponentArrays;

	private:
		/**
		 * Get the component array for a specific component type
		 * 
		 * @return The component array
		 */
		template<typename T>
		std::shared_ptr<ComponentArray<T>> getComponentArray();
	};
}

#include <component_pool.inl>