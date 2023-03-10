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

	void update(float deltaTime) override
	{
		for (auto& entity : m_EnabledEntities)
		{
			auto& audio = entity->getComponent<AudioComponent>();
			audio.volume += 10;
		}
	}
};

TEST(SystemTest, Update)
{
	World world;
	world.registerSystem<AudioSystem>();

	Entity* entity = world.createEntity();
	entity->addComponent<AudioComponent>();

	world.update(0.0f);

	auto& audio = entity->getComponent<AudioComponent>();
	EXPECT_EQ(audio.volume, 10);
}

TEST(SystemTest, EnableDisableEntity)
{
	World world;
	world.registerSystem<AudioSystem>();

	Entity* entity = world.createEntity();
	entity->addComponent<AudioComponent>();

	world.update(0.0f);

	auto& audio = entity->getComponent<AudioComponent>();
	EXPECT_EQ(audio.volume, 10);

	entity->disable();
	world.update(0.0f);
	EXPECT_EQ(audio.volume, 10);

	entity->enable();
	world.update(0.0f);
	EXPECT_EQ(audio.volume, 20);
}

TEST(SystemTest, EntityAdded)
{
	World world;
	world.registerSystem<AudioSystem>();

	Entity* entity = world.createEntity();
	entity->addComponent<AudioComponent>();

	world.update(0.0f);

	Entity* entity2 = world.createEntity();
	entity2->addComponent<AudioComponent>();

	world.update(0.0f);

	auto& audio = entity->getComponent<AudioComponent>();
	auto& audio2 = entity2->getComponent<AudioComponent>();
	EXPECT_EQ(audio.volume, 20);
	EXPECT_EQ(audio2.volume, 10);
}