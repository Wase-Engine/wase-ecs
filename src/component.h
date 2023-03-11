#pragma once

#include <bitset>

namespace wase::ecs
{
	// The max amount of components that can be stored in a single entity
	constexpr size_t MAX_COMPONENTS = 64;

	using ComponentMap = std::bitset<MAX_COMPONENTS>;

	struct Component
	{
		
	};
}