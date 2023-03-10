#pragma once

#include <cstdint>

#include <component.h>

namespace wase::ecs
{
	class World;

	using Id = uint32_t;

	class Entity
	{
	public:
		/**
		 * Default constructor
		 */
		Entity() = default;
		
		/**
		 * Constructor
		 * 
		 * @param id The id of this entity
		 */
		Entity(const Id id);

		/**
		 * Get the id of this entity
		 * 
		 * @return The id of this entity
		 */
		Id getId() const;

		/**
		 * Enable this entity
		 */
		void enable();

		/**
		 * Disable this entity
		 */
		void disable();

		/**
		 * Check if this entity is enabled
		 * 
		 * @return True if this entity is enabled
		 */
		bool isEnabled() const;

		/**
		 * Get the ComponentMap of this entity
		 * 
		 * @return The ComponentMap of this entity
		 */
		ComponentMap getComponentMap() const;

		/**
		 * Get a component from this entity
		 * 
		 * @return A reference to the component
		 */
		template<typename T>
		T& getComponent() const;

		/**
		 * Add a component to this entity
		 * 
		 * @param component The component to add
		 * @return A reference to the component
		 */
		template<typename T, typename... Args>
		T& addComponent(Args&&... args);

		/**
		 * Remove a component from this entity
		 */
		template<typename T>
		void removeComponent();

		/**
		 * Check if this entity has a component
		 * 
		 * @return True if this entity has the component
		 */
		template<typename T>
		bool hasComponent() const;
		

	private:
		Id m_ID;
		bool m_Enabled = true;
		World* m_World;

		friend class World;
	};
}

#include <entity.inl>