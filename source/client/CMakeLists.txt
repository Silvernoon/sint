include_directories(
  ${SINT_BASE_INCLUDES}
  ${SINT_APPLICATION_INCLUDES}
)

file(GLOB client_HEADERS "*.hpp")
file(GLOB client_SOURCES "*.cpp")

add_executable(client WIN32
  $<TARGET_OBJECTS:application> $<TARGET_OBJECTS:base>
  ${client_SOURCES} ${client_HEADERS})
