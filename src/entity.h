#pragma once

#include <cstdint>
#include <optional>

#include <world.h>

namespace wase::ecs
{
	using Id = uint32_t;

	class Entity
	{
	public:
		Id getId() const;

		void enable();

		void disable();

		bool isEnabled() const;

	private:
		Id m_ID;
		bool m_Enabled = true;
		std::optional<World*> m_World;
	};
}

#include <entity.inl>