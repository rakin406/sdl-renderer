#include "../include/entityManager.h"

auto EntityManager::createEntity()
{
    auto entity = this->registry.create();
    this->registry.emplace<bool>(entity, false);
    return entity;
}

auto EntityManager::getAll() {}

void EntityManager::markPurge(auto &entity) {}

void EntityManager::purgeReady() {}
