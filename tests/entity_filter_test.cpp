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
	world.addComponent<TransformComponent>(entity->getId());
	world.addComponent<AudioComponent>(entity->getId());

	EXPECT_TRUE(filter.matches(world.getComponentMap(entity->getId())));
}

TEST(EntityFilterTest, Exclude)
{
	EntityFilter filter;
	filter.require<TransformComponent>();
	filter.exclude<AudioComponent>();

	World world;
	Entity* entity = world.createEntity();
	world.addComponent<TransformComponent>(entity->getId());
	world.addComponent<AudioComponent>(entity->getId());

	EXPECT_FALSE(filter.matches(world.getComponentMap(entity->getId())));
}