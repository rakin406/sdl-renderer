#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <boost/uuid/uuid.hpp>
#include <map>

class EntityManager
{
public:
    // Create entity and return ID
    boost::uuids::uuid createEntity();

    // Mark entity
    void markPurge(boost::uuids::uuid entity);

    // Purge entity that is true
    void purgeReady();

    // Getters and setters
    std::map<boost::uuids::uuid, bool> getEntities() { return this->entities; }
    void setEntities(const std::map<boost::uuids::uuid, bool> &entities)
    {
        this->entities = entities;
    }

private:
    // A map containing entity ID and boolean
    std::map<boost::uuids::uuid, bool> entities;
};

#endif
