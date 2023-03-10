#pragma once

#include <bitset>

#include <component.h>

namespace wase::ecs
{
	class EntityFilter
	{
	public:
		template<typename T>
		void require();

		template<typename T>
		void exclude();

		bool matches(const ComponentMap& componentMap) const;

	private:
		ComponentMap m_RequiredComponents;
		ComponentMap m_ExcludedComponents;
	};
}

#include <entity_filter.inl>