#pragma once

#include <cstdint>

#include <component.h>

namespace wase::ecs
{
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
		 * Check if this entity is enabled
		 * 
		 * @return True if this entity is enabled
		 */
		bool isEnabled() const;

	private:
		Id m_ID;
		bool m_Enabled = true;

		friend class World;
	};
}