#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(WorldTest, EnableEntity)
{
	World world;

	Entity entity = world.createEntity();

	entity.disable();

	EXPECT_FALSE(entity.isEnabled());

	world.enableEntity(entity);

	EXPECT_TRUE(entity.isEnabled());
}

TEST(WorldTest, DisableEntity)
{
	World world;

	Entity entity = world.createEntity();

	world.disableEntity(entity);

	EXPECT_FALSE(entity.isEnabled());
}

TEST(WorldTest, GetEntityByID)
{
	World world;

	Entity entity = world.createEntity();

	EXPECT_EQ(world.getEntityById(entity.getId()), entity);
}

TEST(WorldTest, GetEntityByName)
{
	World world;

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(world.getEntityByName(entity.getName()), entity);
}

TEST(WorldTest, GetEntityNameByID)
{
	World world;

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(world.getEntityNameById(entity.getId()), entity.getName());
}