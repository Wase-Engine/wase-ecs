#pragma once

#include <unordered_map>

namespace wase::ecs
{
	class IComponentArray
	{
	public:
		virtual ~IComponentArray() = default;
	};

	using Entity = uint32_t;

	template<typename T>
	class ComponentArray : public IComponentArray
	{
	public:
		/**
		 * Insert a component into the array
		 * 
		 * @param entity: the entity
		 * @param component: the component to 
		 */
		void insert(const Entity entity, T component);
	
		/**
		 * Remove a component from the array
		 * 
		 * @param entity: the entity
		 */
		void remove(const Entity entity);

		/**
		 * Check if the entity has an instance of the component
		 *
		 * @param entity: the entity
		 * @return True if the entity has an instance of the component
		 */
		bool hasEntity(const Entity entity);

		/**
		 * Get the component data from the array belonging to the entity
		 * 
		 * @param entity: the 
		 * @return the component data
		 */
		T& getData(const Entity entity);

		/**
		 * Get the size of the array
		 * 
		 * @return The size of the array
		 */
		uint32_t getSize() const;

	private:
		std::unordered_map<Entity, T> m_Components;

		uint32_t m_Size = 0;
	};
}
	
#include <component_array.inl>