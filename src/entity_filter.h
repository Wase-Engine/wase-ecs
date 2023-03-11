#pragma once

#include <bitset>

#include <component.h>

namespace wase::ecs
{
	class EntityFilter
	{
	public:
		/**
		 * Require a component to be present in the entity.
		 */
		template<typename T>
		void require();

		/**
		 * Require a component to not be present in the entity.
		 */
		template<typename T>
		void exclude();

		/**
		 * Check if a ComponentMap matches the filter.
		 * 
		 * @param componentMap Component map.
		 * @return True if the component map matches the filter.
		 */
		bool matches(const ComponentMap& componentMap) const;

	private:
		ComponentMap m_RequiredComponents;
		ComponentMap m_ExcludedComponents;
	};
}

#include <entity_filter.inl>