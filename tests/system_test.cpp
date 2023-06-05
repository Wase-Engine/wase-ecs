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
	AudioSystem()
	{
		getFilter().require<AudioComponent>();
	}

	void onEntityAdded(Entity* entity) override
	{
		m_ComponentPool->getComponent<AudioComponent>(entity->getId()).volume += 10;
	}

	void update(float deltaTime) override
	{
		for (auto& entity : m_EnabledEntities)
		{
			auto& audio = m_ComponentPool->getComponent<AudioComponent>(entity->getId());
			audio.volume += 10;
		}
	}
};

TEST(SystemTest, Start)
{
	World world;
	world.registerSystem<AudioSystem>();

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	auto& audio = world.getComponent<AudioComponent>(entity->getId());

	EXPECT_EQ(audio.volume, 10);
}

TEST(SystemTest, Update)
{
	World world;
	world.registerSystem<AudioSystem>();

	Entity* entity = world.createEntity();
	world.addComponent<AudioComponent>(entity->getId());

	world.update(0.0f);
	
	auto& audio = world.getComponent<AudioComponent>(entity->getId());
	
	EXPECT_EQ(audio.volume, 20);
}

TEST(SystemTest, EnableDisableEntity)
{
	World world;
	world.registerSystem<AudioSystem>();

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
	world.registerSystem<AudioSystem>();

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