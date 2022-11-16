#pragma once

#include <cstdint>
#include <string>

namespace wase::ecs
{
	class Entity
	{
	public:
		/**
		 * Create a new entity
		 * 
		 * @param id: the ID of the entity
		 */
		Entity(const uint32_t id);

		/**
		 * Get the entity id
		 * 
		 * @return the entity id
		 */
		uint32_t getId() const;

		/**
		 * Get the entity name
		 *
		 * @return the entity name
		 */
		std::string getName() const;
		
		/**
		 * Enable the entity
		 */
		void enable();
		
		/**
		 * Disable the entity
		 */
		void disable();

		/**
		 * Check if the entity is enabled
		 * 
		 * @return true if the entity is enabled
		 */
		bool isEnabled() const;

		/**
		 * Check if the entity has a component
		 * 
		 * @return true if the entity has a component
		 */
		template <typename T>
		bool hasComponent() const;

		/**
		 * Get the component of the entity
		 *
		 * @return the component of the entity
		 */
		template <typename T>
		T& getComponent() const;

		/**
		 * Add a component to the entity
		 *
		 * @param component the component to add
		 */
		template <typename T>
		void addComponent();

		/**
		 * Remove the component of the entity
		 */
		template <typename T>
		void removeComponent();

		/**
		 * Remove all components of the entity
		 */
		void removeAllComponents();

		/**
		 * Cast the entity to a uint32_t
		 * 
		 * @return the entity id
		 */
		operator uint32_t() const noexcept;
		
		/**
		 * Compare two entities on id
		 * 
		 * @param other: the other entity
		 * @return true if the entity id's are equal
		 */
		bool operator==(const Entity& other) const;

	private:
		uint32_t m_Id;
	};
}

#include <entity.inl>