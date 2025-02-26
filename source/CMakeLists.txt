cmake_minimum_required(VERSION 3.10.0)
project(sint)

if(NOT CMAKE_TOOLCHAIN_FILE)
  message(
      FATAL_ERROR
        "Please set CMAKE_TOOLCHAIN_FILE with your VCPKG"
    )
endif()

find_package(STEAMAPI REQUIRED)
find_package(IMGUI REQUIRED)

add_executable(sint main.cpp)

target_include_directories(sint PRIVATE ${STEAMAPI_INCLUDE_DIRS})
target_link_libraries(sint PRIVATE ${STEAMAPI_LIBRARIES})

if(STEAMAPI_FOUND)
  message(STATUS "SteamAPI found successfully.")
else()
  message(FATAL_ERROR "SteamAPI not found.")
endif()

# 定义一个自定义目标用于运行程序
add_custom_target(test
    COMMAND $<TARGET_FILE:sint>  # 运行生成的可执行文件
    COMMENT "Running sint..."
    VERBATIM
)

# 设置运行目标依赖于主目标
add_dependencies(test sint)

include(CSharpUtilities)

