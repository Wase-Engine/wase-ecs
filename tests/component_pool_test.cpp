#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

struct TransformComponent : Component 
{
	TransformComponent() = default;
	TransformComponent(float x, float y, float z) : x(x), y(y), z(z) {}

	float x, y, z;
};

TEST(ComponentPoolTest, AddComponent)
{
	EntityPool entityPool;
	ComponentPool componentPool;

	Entity* entity = entityPool.createEntity();
	componentPool.addComponent(entity->getId(), std::make_shared<TransformComponent>(1.0f, 2.0f, 3.0f));

	ASSERT_EQ(componentPool.getComponent<TransformComponent>(entity->getId()).x, 1.0f);
}

TEST(ComponentPoolTest, HasComponent)
{
	EntityPool entityPool;
	ComponentPool componentPool;

	Entity* entity = entityPool.createEntity();
	componentPool.addComponent(entity->getId(), std::make_shared<TransformComponent>(1.0f, 2.0f, 3.0));

	ASSERT_TRUE(componentPool.hasComponent<TransformComponent>(entity->getId()));
}

TEST(ComponentPoolTest, RemoveComponent)
{
	EntityPool entityPool;
	ComponentPool componentPool;

	Entity* entity = entityPool.createEntity();
	componentPool.addComponent(entity->getId(), std::make_shared<TransformComponent>(1.0f, 2.0f, 3.0));

	ASSERT_TRUE(componentPool.hasComponent<TransformComponent>(entity->getId()));

	componentPool.removeComponent<TransformComponent>(entity->getId());

	ASSERT_FALSE(componentPool.hasComponent<TransformComponent>(entity->getId()));
}