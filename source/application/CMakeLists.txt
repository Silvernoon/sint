file(GLOB application_HEADERS "*.hpp")
file(GLOB application_SOURCES "*.cpp")

add_library(application OBJECT ${application_SOURCES})
