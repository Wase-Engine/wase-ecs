#pragma once

#include <bitset>

namespace wase::ecs
{
	constexpr size_t MAX_COMPONENTS = 64;

	using ComponentMap = std::bitset<MAX_COMPONENTS>;

	struct Component
	{
		
	};
}