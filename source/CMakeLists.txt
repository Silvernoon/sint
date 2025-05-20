cmake_minimum_required(VERSION 3.10.0)
project(sint)

if(NOT CMAKE_TOOLCHAIN_FILE)
  message(FATAL_ERROR "Please set CMAKE_TOOLCHAIN_FILE with your VCPKG")
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(STEAMAPI REQUIRED)
if(STEAMAPI_FOUND)
  message(STATUS "SteamAPI found successfully.")
else()
  message(FATAL_ERROR "SteamAPI not found.")
endif()

option(SINT_WITH_GUI ON)
if(SINT_WITH_GUI)
  # SDL
  find_package(SDL3 CONFIG REQUIRED)

  # OpenGL
  option(OPENGL "Use OpenGL" ON)
  if(OPENGL)
    find_package(glad CONFIG REQUIRED)
    set(OpenGL_GL_PREFERENCE "LEGACY")
    find_package(OpenGL REQUIRED)

    add_definitions(-DUSE_OPENGL=${OPENGL})
  endif()

  # Vulkan
  if(VULKAN)
    find_package(Vulkan REQUIRED)
    find_package(VulkanUtilityLibraries CONFIG REQUIRED)
  endif(VULKAN)
endif()

find_library(MONO_LIBRARY mono-2.0 PATHS /usr/lib /usr/local/lib)

# Set Output dir
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../dist)

# Base
set(SINT_BASE_INCLUDES ${PROJECT_SOURCE_DIR}/base)
add_subdirectory(base)

# Application
set(SINT_APPLICATION_INCLUDES ${PROJECT_SOURCE_DIR}/application)
add_subdirectory(application)

# Mono
add_subdirectory(mono)

# Test.
option(TESTING "Build Tests" OFF)
if(TESTING)
  add_subdirectory(test)
endif()
