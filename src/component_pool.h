#pragma once

#include <vector>
#include <array>
#include <memory>
#include <bitset>
#include <unordered_map>
#include <string>

#include <component.h>
#include <entity.h>

namespace wase::ecs
{
	class ComponentPool
	{
	public:
		template<typename T>
		T& getComponent(const Id entityId);

		ComponentMap getComponentMap(const Id entityId) const;

		template<typename T>
		T& addComponent(const Id entityId, std::shared_ptr<T>&& component);

		template<typename T>
		void removeComponent(const Id entityId);

		template<typename T>
		bool hasComponent(const Id entityId);
		
	private:
		using ComponentArray = std::array<std::shared_ptr<Component>, MAX_COMPONENTS>;
		
		std::vector<ComponentArray> m_Components;
		std::vector<ComponentMap> m_ComponentMaps;
	};
}

#include <component_pool.inl>