#include "Entity.hpp"
#include "Compent.cpp"
#include <vector>

Entity::Entity() {}

Entity::~Entity() {}

std::vector<Entity> Entity::GetChildren() { return this->ChildrenEntities; }

std::vector<Compent> Entity::GetCompents() { return this->ChildrenCompents; }
