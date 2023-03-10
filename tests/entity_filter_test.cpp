#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

struct TransformComponent : Component
{
	float x, y, z;
};

struct AudioComponent : Component
{
	float volume;
};

TEST(EntityFilterTest, Require)
{
	EntityFilter filter;
	filter.require<TransformComponent>();
	filter.require<AudioComponent>();

	World world;
	Entity* entity = world.createEntity();
	entity->addComponent<TransformComponent>();
	entity->addComponent<AudioComponent>();

	EXPECT_TRUE(filter.matches(entity->getComponentMap()));
}

TEST(EntityFilterTest, Exclude)
{
	EntityFilter filter;
	filter.require<TransformComponent>();
	filter.exclude<AudioComponent>();

	World world;
	Entity* entity = world.createEntity();
	entity->addComponent<TransformComponent>();
	entity->addComponent<AudioComponent>();

	EXPECT_FALSE(filter.matches(entity->getComponentMap()));
}