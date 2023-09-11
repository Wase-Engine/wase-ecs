[![Wase ECS logo banner](https://wase-engine.com/img/wase-ecs-banner.png)](https://wase-engine.com/)

[![Website badge](https://img.shields.io/website?up_message=online&url=https%3A%2F%2Fwase-engine.com%2F)](https://wase-engine.com/)
[![Discord badge](https://img.shields.io/discord/864845724444393472?label=discord)](https://discord.gg/2RBMMxMJ7R)
[![Mit License badge](https://img.shields.io/github/license/wase-engine/wase-ecs)](https://github.com/Wase-Engine/wase-ecs/blob/main/LICENSE)
[![Issues badge](https://img.shields.io/github/issues/Wase-Engine/wase-ecs)](https://github.com/Wase-ECS/wase-ecs/issues)
![Lines badge](https://img.shields.io/tokei/lines/github/Wase-Engine/wase-ecs)
![Stars badge](https://img.shields.io/github/stars/Wase-Engine/wase-ecs?style=social)

Wase ECS is an open source ECS library made with C++17.

## Setup
To set up Wase ECS you will need CMake and C++17.
```
mkdir build && cd build
cmake ..
```
To include tests you can add the `-Denable_test=1` flag to the cmake command.

## Usage

To include Wase ECS to your project you can include the `ecs.h` file.

### Creating a World object
First you need to set up a World object. The World handles everything for the ECS.
```c++
wase::ecs::World world;
```

You can update all the systems that are registered in the world with the update method.
```c++
world.update(deltaTime);
```

### Managing entities
With the world object you are able to manage your entities.
```c++
world.createEntity();
Entity* entity = world.getEntity(entityId);
world.destroyEntity(entity->getId());
```

The Entity class has some methods itself too to manage the entity state.
```c++
Id id = entity->getId();
world.enableEntity(id);
world.disableEntity(id);
bool enabled = entity.isEnabled();
```

### Components
You can create custom components yourself.
```c++
struct TransformComponent : wase::ecs::Component
{
    int x = 0;
    int y = 0;
};
```

To manage components on entities you can use the methods in the Entity class.
```c++
world.addComponent<TransformComponent>(entityId);
TransformComponent& component = world.getComponent<TransformComponent>(entityId);
bool hasComponent = world.hasComponent<TransformComponent>(entityId);
world.removeComponent<TransformComponent>(entityId);
```

### Systems
You can create custom systems yourself.
```c++
class PhysicsSystem : public wase::ecs::System 
{
};
```

You can register the new system to the world object.
```c++
world.registerSystem<PhysicsSystem>();
```
When a system gets registered it adds all the entities in the world to it that match the entity filter.

#### Entity filter
With the entity filter you can specify which entities should be added to the system depending on their components.
```c++
class PhysicsSystem : public wase::ecs::System 
{
public:
    PhysicsSystem()
    {
        getFilter().require<TransformComponent>();
    }
};
```
This will require the TransformComponent for any entities to be added to the PhysicsSystem.
You can also use the exclude filter so that entities with this component will not be added.
```c++
class PhysicsSystem : public wase::ecs::System 
{
public:
    PhysicsSystem()
    {
        getFilter().exclude<TransformComponent>();
    }
};
```

#### Updating systems
All registered systems get updated when the update method on the world object is being executed.
```c++
world.update(deltaTime);
```

You can add logic to the update method of the system.
```c++
class PhysicsSystem : public wase::ecs::System 
{
public:
    PhysicsSystem()
    {
        getFilter().require<TransformComponent>();
    }
    
    void update(const float deltaTime) override
    {
        for(Entity* entity : m_EnabledEntities)
        {
            auto& transform = m_ComponentPool->getComponent<TransformComponent>(entity->getId());
            transform.x++;
            transform.y++;
        }
    }
};
```
`m_EnabledEntities` holds all the entities that are matched with the entity filter and are enabled. You could also make use of `m_DisabledEntities`, this contains all the matching entities that are disabled.

## Contributing
If you want to contribute to Wase ECS you can head over to the [contributing](https://github.com/Wase-ECS/wase-ecs/blob/main/CONTRIBUTING.md) page for more information.
