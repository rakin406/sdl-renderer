#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <boost/uuid/uuid.hpp>
#include <map>

class EntityManager
{
public:
    // A map containing entity ID and boolean
    std::map<boost::uuids::uuid, bool> entities;

    // Default constructor
    EntityManager() = default;

    // Create entity and return ID
    boost::uuids::uuid createEntity();

    // Get all entities
    std::map<boost::uuids::uuid, bool> getAll() const;

    // Mark entity
    void markPurge(boost::uuids::uuid entity);

    // Purge entity that is true
    void purgeReady();
};

#endif
