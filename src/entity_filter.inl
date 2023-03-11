#pragma once

#include <entity_filter.h>
#include <type_id.h>

namespace wase::ecs
{
	template<typename T>
	void EntityFilter::require()
	{
		m_RequiredComponents.set(TypeID::getTypeID<T>());
	}

	template<typename T>
	void EntityFilter::exclude()
	{
		m_ExcludedComponents.set(TypeID::getTypeID<T>());
	}
}