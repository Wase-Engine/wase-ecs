#pragma once

#include <cstdint>
#include <string>

namespace wase::ecs
{
	class Entity
	{
	public:
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