#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

struct PositionComponent : public Component
{
	PositionComponent() {}
	PositionComponent(float x, float y) : x(x), y(y) {}
	
	float x;
	float y;
};

TEST(ComponentArrayTest, InsertComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent component(10, 5);

	ComponentArray<PositionComponent> componentArray;

	componentArray.insert(entity, component);

	EXPECT_EQ(componentArray.getSize(), 1);
}

TEST(ComponentArrayTest, RemoveComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent component(10, 5);

	ComponentArray<PositionComponent> componentArray;

	componentArray.insert(entity, component);

	EXPECT_EQ(componentArray.getSize(), 1);

	componentArray.remove(entity);

	EXPECT_EQ(componentArray.getSize(), 0);
}

TEST(ComponentArrayTest, HasEntity)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent component(10, 5);

	ComponentArray<PositionComponent> componentArray;

	ASSERT_FALSE(componentArray.hasEntity(entity));

	componentArray.insert(entity, component);

	ASSERT_TRUE(componentArray.hasEntity(entity));
}

TEST(ComponentArrayTest, GetData)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent component(10, 5);

	ComponentArray<PositionComponent> componentArray;
	
	componentArray.insert(entity, component);

	PositionComponent& data = componentArray.getData(entity);

	EXPECT_EQ(data.x, 10.0f);
	EXPECT_EQ(data.y, 5.0f);
}