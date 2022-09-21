#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <map>

#include "../include/entityManager.h"

boost::uuids::uuid EntityManager::createEntity()
{
    boost::uuids::uuid entity = boost::uuids::random_generator()();
    this->entities[entity] = false;
    return entity;
}

void EntityManager::markPurge(boost::uuids::uuid entity)
{
    this->entities[entity] = true;
}

void EntityManager::purgeReady()
{
    // Removes all entities that have a value of true, only called once all
    // other purges have been called.
    for (const auto &[key, val] : this->entities)
    {
        if (val)
        {
            this->entities.erase(key);
        }
    }
}
