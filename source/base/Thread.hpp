#pragma once

#include <atomic>
#include <mutex>
#include <thread>

namespace Sint {

using Mutex = std::mutex;
using MutexLocker = std::lock_guard<std::mutex>;

template <typename T> using Atomic = std::atomic<T>;
} // namespace Sint
