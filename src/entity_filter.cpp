#include <entity_filter.h>

namespace wase::ecs
{
	bool EntityFilter::matches(const ComponentMap& componentMap) const
	{
		return (m_RequiredComponents & componentMap) == m_RequiredComponents && (m_ExcludedComponents & componentMap).none();
	}
}