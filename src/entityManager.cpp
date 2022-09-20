#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <map>

#include "../include/entityManager.h"

boost::uuids::uuid EntityManager::createEntity()
{
    boost::uuids::uuid entity = boost::uuids::random_generator()();
    std::map<boost::uuids::uuid, bool> entities = this->getEntities();
    entities[entity] = false;
    this->setEntities(entities);
    return entity;
}

void EntityManager::markPurge(boost::uuids::uuid entity)
{
    std::map<boost::uuids::uuid, bool> entities = this->getEntities();
    entities[entity] = true;
    this->setEntities(entities);
}

void EntityManager::purgeReady()
{
    // Get all entities
    std::map<boost::uuids::uuid, bool> entities = this->getEntities();

    // Removes all entities that have a value of true, only called once all
    // other purges have been called.
    for (const auto &[key, val] : entities)
    {
        if (val)
        {
            entities.erase(key);
        }
    }

    // Set modified entities
    this->setEntities(entities);
}
