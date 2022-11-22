#include <component_pool.h>

namespace wase::ecs
{
	ComponentPool::ComponentPool(const uint8_t maxAmountOfComponents)
		: m_MaxAmountOfComponents(maxAmountOfComponents)
	{

	}

	uint8_t ComponentPool::size() const
	{
		return m_Size;
	}
}