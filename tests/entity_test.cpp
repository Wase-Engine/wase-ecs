#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(EntityTest, CreateEntityID)
{
	World world;

	Entity entity = world.createEntity();
	
	EXPECT_EQ(entity.getId(), 0);
}

// Test for creating an entity with a name
TEST(EntityTest, CreateEntityName)
{
	World world;

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(entity.getName(), "Test Entity");
}

// Test for creating an entity with the same name as another entity
TEST(EntityTest, CreateEntitySameName)
{
	World world;

	Entity entity1 = world.createEntity("Test Entity");
	
	EXPECT_THROW(world.createEntity("Test Entity"), std::exception);
}

// Test for getting the entity id
TEST(EntityTest, GetEntityID)
{
	World world;

	Entity entity = world.createEntity();

	EXPECT_EQ(entity.getId(), 0);
}

// Test for getting the entity name
TEST(EntityTest, GetEntityName)
{
	World world;

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(entity.getName(), "Test Entity");
}

// Test for enabling the entity
TEST(EntityTest, EnableEntity)
{
	World world;

	Entity entity = world.createEntity();

	entity.enable();

	EXPECT_TRUE(entity.isEnabled());
}

// Test for disabling the entity
TEST(EntityTest, DisableEntity)
{
	World world;

	Entity entity = world.createEntity();

	entity.disable();

	EXPECT_FALSE(entity.isEnabled());
}

// Test for checking if the entity is enabled
TEST(EntityTest, IsEntityEnabled)
{
	World world;

	Entity entity = world.createEntity();

	EXPECT_TRUE(entity.isEnabled());
}

// Test for checking if two entities are the same
TEST(EntityTest, IsSameEntity)
{
	World world;

	Entity entity1 = world.createEntity();
	Entity entity2 = entity1;

	EXPECT_TRUE(entity1 == entity2);
}