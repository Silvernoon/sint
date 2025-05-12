include_directories(${SINT_BASE_INCLUDES})

add_executable(test windowTest.cpp $<TARGET_OBJECTS:base>)

target_include_directories(test PRIVATE ${STEAMAPI_INCLUDE_DIRS})
target_link_libraries(test PRIVATE ${STEAMAPI_LIBRARIES})

target_link_libraries(test PRIVATE SDL3)
