#pragma once

#include <cstdint>

#include <component.h>

namespace wase::ecs
{
	class World;

	using Id = uint32_t;

	class Entity
	{
	public:
		Entity() = default;

		Entity(const Id id);

		Id getId() const;

		void enable();

		void disable();

		bool isEnabled() const;

		ComponentMap getComponentMap() const;

		template<typename T>
		T& getComponent();

		template<typename T, typename... Args>
		T& addComponent(Args&&... args);

		template<typename T>
		void removeComponent();

		template<typename T>
		bool hasComponent();
		

	private:
		Id m_ID;
		bool m_Enabled = true;
		World* m_World;

		friend class World;
	};
}

#include <entity.inl>