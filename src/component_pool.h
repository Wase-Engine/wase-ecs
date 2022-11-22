#pragma once

#include <cstdint>
#include <array>
#include <memory>

namespace wase::ecs
{
	using Entity = uint32_t;
	
	class ComponentPool
	{
	public:
		ComponentPool(const uint8_t maxAmountOfComponents);

		template<typename T>
		T& addComponent(Entity entity, std::shared_ptr<T>&& component);

		template<typename T>
		bool hasComponent(Entity entity);

		template<typename T>
		T& getComponent(Entity entity);

		template<typename T>
		void removeComponent(Entity entity);

		uint8_t size() const;

	private:
		uint8_t m_MaxAmountOfComponents;
		uint8_t m_Size;
	};
}

#include <component_pool.inl>