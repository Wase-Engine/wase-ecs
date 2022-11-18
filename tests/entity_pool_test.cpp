#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(EntityPoolTest, CreateEntityID)
{
	EntityPool pool(2);

	Entity entity1 = pool.createEntity();
	Entity entity2 = pool.createEntity();

	EXPECT_EQ(entity1, 0);
	EXPECT_EQ(entity2, 1);
}

TEST(EntityPoolTest, CreateEntityName)
{
	EntityPool pool(1);

	Entity entity = pool.createEntity("Test Entity");

	EXPECT_EQ(entity, 0);
	EXPECT_EQ(pool.getEntityName(entity), "Test Entity");
}

TEST(EntityPoolTest, CreateEntitySameName)
{
	EntityPool pool(2);

	Entity entity1 = pool.createEntity("Test Entity");

	EXPECT_ANY_THROW(pool.createEntity("Test Entity"));
}

TEST(EntityPoolTest, DestroyEntity)
{
	EntityPool pool(3);
	Entity entity = pool.createEntity("Test");

	EXPECT_EQ(pool.getSize(), 1);
	EXPECT_EQ(pool.getEntityByName("Test"), entity);
	EXPECT_EQ(pool.getEntityName(entity), "Test");

	pool.destroyEntity(entity);
	
	pool.createEntity("One");
	pool.createEntity();
	pool.createEntity();

	EXPECT_EQ(pool.getSize(), 3);
	EXPECT_EQ(pool.getEntityByName("One"), 1);
	EXPECT_EQ(pool.getEntityByName("Test"), -1);
	EXPECT_EQ(pool.getEntityName(entity), "");
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

TEST(EntityPoolTest, GetEntityByName)
{
	EntityPool pool(1);

	Entity entity = pool.createEntity("Test Entity");

	EXPECT_EQ(pool.getEntityByName("Test Entity"), entity);
}

TEST(EntityPoolTest, GetEntityNameByID)
{
	EntityPool pool(1);

	Entity entity = pool.createEntity("Test Entity");

	EXPECT_EQ(pool.getEntityName(entity), "Test Entity");
}

TEST(EntityPoolTest, EnableEntity)
{
	EntityPool pool(1);

	Entity entity = pool.createEntity();

	pool.disableEntity(entity);

	EXPECT_FALSE(pool.isEnabled(entity));

	pool.enableEntity(entity);

	EXPECT_TRUE(pool.isEnabled(entity));
}

TEST(EntityPoolTest, DisableEntity)
{
	EntityPool pool(1);

	Entity entity = pool.createEntity();

	pool.disableEntity(entity);

	EXPECT_FALSE(pool.isEnabled(entity));
}