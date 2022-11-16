#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

class FirstTestComponent : public Component {};
class SecondTestComponent : public Component {};

TEST(EntityTest, GetEntityID)
{
	World world(1);

	Entity entity = world.createEntity();

	EXPECT_EQ(entity.getId(), 0);
}

TEST(EntityTest, GetEntityName)
{
	World world(1);

	Entity entity = world.createEntity("Test Entity");

	EXPECT_EQ(entity.getName(), "Test Entity");
}

TEST(EntityTest, EnableEntity)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.enable();

	EXPECT_TRUE(entity.isEnabled());
}

TEST(EntityTest, DisableEntity)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.disable();

	EXPECT_FALSE(entity.isEnabled());
}

TEST(EntityTest, IsEntityEnabled)
{
	World world(1);

	Entity entity = world.createEntity();

	EXPECT_TRUE(entity.isEnabled());
}

TEST(EntityTest, IsSameEntity)
{
	World world(1);

	Entity entity1 = world.createEntity();
	Entity entity2 = entity1;

	EXPECT_TRUE(entity1 == entity2);
}

TEST(EntityTest, AddComponent)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.addComponent<FirstTestComponent>();

	EXPECT_TRUE(entity.hasComponent<FirstTestComponent>());
}

TEST(EntityTest, RemoveComponent)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.addComponent<FirstTestComponent>();

	EXPECT_TRUE(entity.hasComponent<FirstTestComponent>());

	entity.removeComponent<FirstTestComponent>();

	EXPECT_FALSE(entity.hasComponent<FirstTestComponent>());
}

TEST(EntityTest, GetComponent)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.addComponent<FirstTestComponent>();

	EXPECT_TRUE(&entity.getComponent<FirstTestComponent>() != nullptr);
}

TEST(EntityTest, GetNonExistingComponent)
{
	World world(1);

	Entity entity = world.createEntity();

	EXPECT_ANY_THROW(entity.getComponent<FirstTestComponent>());
}

TEST(EntityTest, HasComponent)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.addComponent<FirstTestComponent>();

	EXPECT_TRUE(entity.hasComponent<FirstTestComponent>());
}

TEST(EntityTest, RemoveAllComponents)
{
	World world(1);

	Entity entity = world.createEntity();

	entity.addComponent<FirstTestComponent>();
	entity.addComponent<SecondTestComponent>();

	EXPECT_TRUE(entity.hasComponent<FirstTestComponent>());
	EXPECT_TRUE(entity.hasComponent<SecondTestComponent>());

	entity.removeAllComponents();

	EXPECT_FALSE(entity.hasComponent<FirstTestComponent>());
	EXPECT_FALSE(entity.hasComponent<SecondTestComponent>());
}