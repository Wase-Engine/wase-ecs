#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(WorldTest, CreateEntityID)
{
	World world(2);

	Entity entity1 = world.createEntity();
	Entity entity2 = world.createEntity();

	EXPECT_EQ(entity1.getId(), 0);
	EXPECT_EQ(entity2.getId(), 1);
}

TEST(WorldTest, CreateEntityName)
{
	World world(1);

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(entity.getId(), 0);
	EXPECT_EQ(entity.getName(), "Test Entity");
}

TEST(WorldTest, CreateEntitySameName)
{
	World world(2);

	Entity entity1 = world.createEntity("Test Entity");

	EXPECT_ANY_THROW(world.createEntity("Test Entity"));
}

TEST(WorldTest, EnableEntity)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.disable();

	EXPECT_FALSE(entity.isEnabled());

	world.enableEntity(entity);

	EXPECT_TRUE(entity.isEnabled());
}

TEST(WorldTest, DisableEntity)
{
	World world(1);

	Entity entity = world.createEntity();

	world.disableEntity(entity);

	EXPECT_FALSE(entity.isEnabled());
}

TEST(WorldTest, GetEntityByID)
{
	World world(1);

	Entity entity = world.createEntity();

	EXPECT_EQ(world.getEntityById(entity.getId()), entity);
}

TEST(WorldTest, GetEntityByName)
{
	World world(1);

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(world.getEntityByName(entity.getName()), entity);
}

TEST(WorldTest, GetEntityNameByID)
{
	World world(1);

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(world.getEntityNameById(entity.getId()), entity.getName());
}