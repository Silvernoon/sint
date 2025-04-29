include_directories(${SINT_BASE_INCLUDES})

add_executable(test main.cpp $<TARGET_OBJECTS:base>)

target_include_directories(test PRIVATE ${STEAMAPI_INCLUDE_DIRS})
target_link_libraries(test PRIVATE ${STEAMAPI_LIBRARIES})

target_link_libraries(test PRIVATE SDL3)

# 定义一个自定义目标用于运行程序
add_custom_target(
  runtest
  COMMAND $<TARGET_FILE:test> # 运行生成的可执行文件
  COMMENT "Running test..."
  VERBATIM)

# 设置运行目标依赖于主目标
add_dependencies(runtest test)
