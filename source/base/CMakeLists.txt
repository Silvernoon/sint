file(GLOB base_HEADERS "*.hpp")
file(GLOB base_SOURCES "*.cpp")

add_library(base OBJECT ${base_SOURCES} ${base_HEADERS})
