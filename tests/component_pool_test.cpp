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

TEST(ComponentPoolTest, RegisterDuplicateComponentType)
{
	ComponentPool componentPool;
	
	componentPool.registerComponent<PositionComponent>();
	
	ASSERT_ANY_THROW(componentPool.registerComponent<PositionComponent>());
}

TEST(ComponentPoolTest, AddComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent positionComponent(20, 10);
	
	ComponentPool componentPool;
	componentPool.registerComponent<PositionComponent>();

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.addComponent<PositionComponent>(entity, positionComponent);
	
	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));
}

TEST(ComponentPoolTest, RemoveComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent positionComponent(20, 10);

	ComponentPool componentPool;
	componentPool.registerComponent<PositionComponent>();

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.addComponent<PositionComponent>(entity, positionComponent);

	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.removeComponent<PositionComponent>(entity);

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));
}

TEST(ComponentPoolTest, GetComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent positionComponent(20, 10);

	ComponentPool componentPool;
	componentPool.registerComponent<PositionComponent>();
	componentPool.addComponent<PositionComponent>(entity, positionComponent);

	PositionComponent& component = componentPool.getComponent<PositionComponent>(entity);

	ASSERT_EQ(component.x, 20.0f);
	ASSERT_EQ(component.y, 10.0f);
}

TEST(ComponentPoolTest, HasComponent)
{
	World world;
	Entity entity = world.createEntity();
	PositionComponent positionComponent(20, 10);

	ComponentPool componentPool;
	componentPool.registerComponent<PositionComponent>();

	ASSERT_FALSE(componentPool.hasComponent<PositionComponent>(entity));

	componentPool.addComponent<PositionComponent>(entity, positionComponent);

	ASSERT_TRUE(componentPool.hasComponent<PositionComponent>(entity));
}