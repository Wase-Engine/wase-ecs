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
	World world;
	ComponentPool componentPool;
	Entity entity = world.createEntity();

	PositionComponent component = componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());
	component.x = 10.0f;
	component.y = 5.0f;
	
	ASSERT_EQ(component.x, 10.0f);
	ASSERT_EQ(component.y, 5.0f);
}

TEST(ComponentPoolTest, RemoveComponent)
{
	World world;
	ComponentPool componentPool;
	Entity entity = world.createEntity();

	PositionComponent component = componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.removeComponent<PositionComponent>(entity);

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));
}

TEST(ComponentPoolTest, GetComponent)
{
	World world;
	ComponentPool componentPool;
	Entity entity = world.createEntity();

	componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	PositionComponent component = componentPool.getComponent<PositionComponent>(entity);
	component.x = 10.0f;
	component.y = 5.0f;

	ASSERT_EQ(component.x, 10.0f);
	ASSERT_EQ(component.y, 5.0f);
}

TEST(ComponentPoolTest, HasComponent)
{
	World world;
	ComponentPool componentPool;
	Entity entity = world.createEntity();

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.addComponent<PositionComponent>(entity, std::make_shared<PositionComponent>());

	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));
}