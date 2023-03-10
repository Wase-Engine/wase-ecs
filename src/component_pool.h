#pragma once

#include <vector>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_map>
#include <string>

#include <component.h>
#include <entity.h>

namespace wase::ecs
{
	class World;

	class ComponentPool
	{
	public:
		/**
		 * Get a component beloning to an entity
		 * 
		 * @param entityId The id of the entity
		 * @return A reference to the component
		 */
		template<typename T>
		T& getComponent(const Id entityId) const;

		/**
		 * Add a component to an entity
		 * 
		 * @param entityId The id of the entity
		 * @param component The component to add
		 * @return A reference to the component
		 */
		template<typename T>
		T& addComponent(const Id entityId, std::shared_ptr<T>&& component);

		/**
		 * Remove a component from an entity
		 * 
		 * @param entityId The id of the entity
		 */
		template<typename T>
		void removeComponent(const Id entityId);

		/**
		 * Check if an entity has a component
		 * 
		 * @param entityId The id of the entity
		 * @return True if the entity has the component
		 */
		template<typename T>
		bool hasComponent(const Id entityId) const;

		/**
		 * Get the component map of an entity
		 * 
		 * @param entityId The id of the entity
		 * @return The component map
		 */
		ComponentMap getComponentMap(const Id entityId) const;
		
	private:
		using ComponentArray = std::array<std::shared_ptr<Component>, MAX_COMPONENTS>;
		
		std::vector<ComponentArray> m_Components;
		std::vector<ComponentMap> m_ComponentMaps;
	};
}

#include <component_pool.inl>