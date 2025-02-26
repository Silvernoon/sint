#ifndef ENEITY_HPP
#define ENEITY_HPP

#include <vector>

// Forward declaration
class Compent;

class Entity {
public:
  Entity();
  Entity(Entity &&) = default;
  Entity(const Entity &) = default;
  Entity &operator=(Entity &&) = default;
  Entity &operator=(const Entity &) = default;
  ~Entity();

  std::vector<Compent> GetCompents();
  std::vector<Entity> GetChildren();

private:
  Entity *ParentEntity;
  std::vector<Entity> ChildrenEntities;
  std::vector<Compent> ChildrenCompents;
};

#endif // !ENEITY_HPP
