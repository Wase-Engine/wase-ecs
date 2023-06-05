#include <gtest/gtest.h>

#include <ecs.h>

using namespace wase::ecs;

struct AudioComponent : Component
{
	float volume;
};

class AudioSystem : public System
{
public:
	AudioSystem(const int increment)
		: m_Increment(increment)
	{
		getFilter().require<AudioComponent>();
	}

	void onEntityAdded(Entity* entity) override
	{
		m_ComponentPool->getComponent<AudioComponent>(entity->getId()).volume += m_Increment;
	}

	void update(float deltaTime) override
	{
		for (auto& entity : m_EnabledEntities)
		{
			auto& audio = m_ComponentPool->getComponent<AudioComponent>(entity->getId());
			audio.volume += m_Increment;
		}
	}

private:
	int m_Increment = 0;
};

class DoubleSystem : public System
{
public:
	DoubleSystem(const int a, const int b)
		: m_A(a), m_B(b)
	{
		getFilter().require<AudioComponent>();
	}

	void onEntityAdded(Entity* entity) override
	{
		m_ComponentPool->getComponent<AudioComponent>(entity->getId()).volume = m_A + m_B;
	}

private:
	int m_A = 0;
	int m_B = 0;
};

TEST(SystemTest, DoubleArguments)
{
	World world;
	world.registerSystem<DoubleSystem>(10, 5);

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	auto& audio = world.getComponent<AudioComponent>(entity->getId());

	EXPECT_EQ(audio.volume, 15);
}

TEST(SystemTest, Start)
{
	World world;
	world.registerSystem<AudioSystem>(10);

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	auto& audio = world.getComponent<AudioComponent>(entity->getId());

	EXPECT_EQ(audio.volume, 10);
}

TEST(SystemTest, Update)
{
	World world;
	world.registerSystem<AudioSystem>(10);

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	world.update(0.0f);
	
	auto& audio = world.getComponent<AudioComponent>(entity->getId());
	
	EXPECT_EQ(audio.volume, 20);
}

TEST(SystemTest, EnableDisableEntity)
{
	World world;
	world.registerSystem<AudioSystem>(10);

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	world.update(0.0f);

	auto& audio = world.getComponent<AudioComponent>(entity->getId());
	EXPECT_EQ(audio.volume, 20);

	world.disableEntity(entity->getId());
	world.update(0.0f);
	EXPECT_EQ(audio.volume, 20);

	world.enableEntity(entity->getId());
	world.update(0.0f);
	EXPECT_EQ(audio.volume, 30);
}

TEST(SystemTest, EntityAdded)
{
	World world;
	world.registerSystem<AudioSystem>(10);

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	world.update(0.0f);

	Entity* entity2 = world.createEntity();
	world.addComponent<AudioComponent>(entity2->getId());

	world.update(0.0f);

	auto& audio = world.getComponent<AudioComponent>(entity->getId());
	auto& audio2 = world.getComponent<AudioComponent>(entity2->getId());
	EXPECT_EQ(audio.volume, 30);
	EXPECT_EQ(audio2.volume, 20);
}