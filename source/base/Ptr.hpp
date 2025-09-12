#include <memory>

#define CLASS_Ptr(ClassName)                                                   \
  class ClassName;                                                             \
  using ClassName##Ptr = std::shared_ptr<ClassName>;                           \
  using ClassName##ConstPtr = std::shared_ptr<const ClassName>;                \
  using ClassName##WeakPtr = std::weak_ptr<ClassName>;                         \
  using ClassName##ConstWeakPtr = std::weak_ptr<const ClassName>;              \
  using ClassName##UPtr = std::unique_ptr<ClassName>;                          \
  using ClassName##ConstUPtr = std::unique_ptr<const ClassName>
