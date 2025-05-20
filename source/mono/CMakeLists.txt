include_directories(${SINT_BASE_INCLUDES})

file(GLOB mono_HEADERS "*.hpp")
file(GLOB mono_SOURCES "*.cpp")

add_library(mono SHARED ${mono_SOURCES} ${mono_HEADERS})
