#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

struct PositionComponent : public Component
{
	float x;
	float y;
};

struct SpriteComponent : public Component
{
	float width;
	float height;
};

TEST(ComponentPoolTest, AddComponent)
{
	World world(1);
	ComponentPool componentPool(1);
	Entity entity = world.createEntity();

	PositionComponent component = componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());
	component.x = 10.0f;
	component.y = 5.0f;
	
	ASSERT_EQ(component.x, 10.0f);
	ASSERT_EQ(component.y, 5.0f);
	ASSERT_EQ(componentPool.size(), 1);
}

TEST(ComponentPoolTest, TooManyComponents)
{
	World world(1);
	ComponentPool componentPool(1);
	Entity entity = world.createEntity();
	
	componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	ASSERT_ANY_THROW(componentPool.addComponent<SpriteComponent>(entity, std::make_shared<SpriteComponent>()));
}

TEST(ComponentPoolTest, RemoveComponent)
{
	World world(1);
	ComponentPool componentPool(1);
	Entity entity = world.createEntity();

	PositionComponent component = componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	ASSERT_EQ(componentPool.size(), 1);

	componentPool.removeComponent<PositionComponent>(entity);

	ASSERT_EQ(componentPool.size(), 0);
}

TEST(ComponentPoolTest, GetComponent)
{
	World world(1);
	ComponentPool componentPool(1);
	Entity entity = world.createEntity();

	componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	PositionComponent component = componentPool.getComponent<PositionComponent>(entity);
	component.x = 10.0f;
	component.y = 5.0f;

	ASSERT_EQ(component.x, 10.0f);
	ASSERT_EQ(component.y, 5.0f);
	ASSERT_EQ(componentPool.size(), 1);
}

TEST(ComponentPoolTest, HasComponent)
{
	World world(1);
	ComponentPool componentPool(1);
	Entity entity = world.createEntity();

	componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));
}