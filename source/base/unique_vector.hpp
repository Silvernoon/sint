#include <cstdint>
#include <vector>

template <typename T> class UniqueVector {
  std::vector<T> container;

public:
  void Push(T value) {
    for (auto &i : container)
      if (!strcmp(value, i)) // strcmp(...)在字符串匹配时返回0
        return;              // 如果层/扩展的名称已在容器中，直接返回
    container.push_back(value);
  }
  T *const Data() { return container.data(); }
  uint32_t Size() { return container.size(); }
};
