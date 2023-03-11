#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

TEST(EntityPoolTest, CreateEntity)
{
	EntityPool pool;
	Entity* entity = pool.createEntity();

	EXPECT_NE(nullptr, entity);
}

TEST(EntityPoolTest, GetEntity)
{
	EntityPool pool;
	Entity* entity = pool.createEntity();

	EXPECT_EQ(entity, pool.getEntity(entity->getId()));
}

TEST(EntityPoolTest, GetEntities)
{
	EntityPool pool;
	Entity* entity1 = pool.createEntity();
	Entity* entity2 = pool.createEntity();

	std::vector<Entity*> entities = pool.getEntities();

	EXPECT_EQ(2, entities.size());
	EXPECT_EQ(entity1, entities[0]);
	EXPECT_EQ(entity2, entities[1]);
}

TEST(EntityPoolTest, DestroyEntity)
{
	EntityPool pool;
	Entity* entity = pool.createEntity();

	pool.destroyEntity(entity->getId());

	EXPECT_EQ(nullptr, pool.getEntity(0));
}