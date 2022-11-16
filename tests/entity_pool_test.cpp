#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(EntityPoolTest, CreateEntity)
{
	EntityPool pool(1);
	Entity entity = pool.createEntity();

	EXPECT_EQ(pool.getSize(), 1);
}

TEST(EntityPoolTest, DestroyEntity)
{
	EntityPool pool(1);
	Entity entity = pool.createEntity();

	EXPECT_EQ(pool.getSize(), 1);

	pool.destroyEntity(entity);

	EXPECT_EQ(pool.getSize(), 0);
}

TEST(EntityPoolTest, IsFull)
{
	EntityPool pool(3);
	Entity entity1 = pool.createEntity();
	Entity entity2 = pool.createEntity();
	Entity entity3 = pool.createEntity();

	EXPECT_EQ(pool.getSize(), 3);
	
	EXPECT_ANY_THROW(pool.createEntity());
}