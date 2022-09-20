#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

class EntityManager
{
public:
    entt::registry registry;

    EntityManager() = default;

    auto createEntity();
    auto getAll();
    void markPurge(auto &entity);
    void purgeReady();
};

#endif
