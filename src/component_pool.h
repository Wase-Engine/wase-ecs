#pragma once

#include <cstdint>
#include <array>
#include <memory>
#include <vector>

#include <component.h>

namespace wase::ecs
{
	using Entity = uint32_t;
	
	class ComponentPool
	{
	public:
		/**
		 * Add a component to an entity
		 * 
		 * @param entity: the entity to add the component to
		 * @param component: the component to add
		 * @return The component
		 */
		template<typename T>
		T& addComponent(Entity entity, std::shared_ptr<T>&& component);

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
		using ComponentArray = std::array<std::shared_ptr<Component>, MAX_COMPONENTS>;

		std::vector<ComponentArray> m_ComponentArrays;
	};
}

#include <component_pool.inl>