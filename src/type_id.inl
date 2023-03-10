#pragma once

#include <type_id.h>
#include <component.h>

namespace wase::ecs
{
	template<typename T>
	size_t TypeID::getTypeID()
	{
		const std::string typeName = typeid(T).name();

		if (m_ComponentTypeIds.size() >= MAX_COMPONENTS)
			throw std::runtime_error("Too many components");

		if (m_ComponentTypeIds.find(typeName) == m_ComponentTypeIds.end())
			m_ComponentTypeIds[typeName] = m_ComponentTypeIds.size();

		return m_ComponentTypeIds[typeName];
	}
}