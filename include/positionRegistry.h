#ifndef POSITION_REGISTRY_H
#define POSITION_REGISTRY_H

#include <boost/uuid/uuid.hpp>
#include <map>
#include <vector>

#include "components.h"

// Position component registry
class PositionRegistry
{
public:
    void set(boost::uuids::uuid entity, Position position)
    {
        this->positions[entity] = position;
    }

    Position get(boost::uuids::uuid entity) { return this->positions[entity]; }

    void remove(boost::uuids::uuid entity) { this->positions.erase(entity); }

    void purge(const std::vector<boost::uuids::uuid> &entities)
    {
        for (const auto &entity : entities)
        {
            this->positions.erase(entity);
        }
    }

private:
    // A map containing ID and position values
    std::map<boost::uuids::uuid, Position> positions{};
};

#endif
