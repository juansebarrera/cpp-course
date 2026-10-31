add_library(mod05_mem src/mem.cpp)
target_include_directories(mod05_mem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod05_mem PRIVATE course_warnings)

add_executable(mod05_demo src/main.cpp)
target_link_libraries(mod05_demo PRIVATE mod05_mem course_warnings)

add_executable(mod05_tests tests/test_mem.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod05_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod05_tests PRIVATE mod05_mem course_warnings)

course_add_test(mod05_tests)
