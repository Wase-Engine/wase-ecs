#pragma once

#include <vector>

#include <entity_filter.h>
#include <entity.h>

namespace wase::ecs
{
	class System
	{
	public:
		virtual ~System() = default;

		virtual void update(const float deltaTime);

		void addEntity(Entity* entity);

		void removeEntity(Entity* entity);

		void enableEntity(Entity* entity);

		void disableEntity(Entity* entity);

		void checkEntity(Entity* entity);

	protected:
		EntityFilter& getFilter();

	protected:
		std::vector<Entity*> m_EnabledEntities;
		std::vector<Entity*> m_DisabledEntities;
		
	private:
		EntityFilter m_Filter;

		friend class SystemPool;
	};
}