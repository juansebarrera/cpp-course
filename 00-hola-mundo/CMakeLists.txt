add_library(mod00_hello src/hello.cpp)
target_include_directories(mod00_hello PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod00_hello PRIVATE course_warnings)

add_executable(mod00_demo src/main.cpp)
target_link_libraries(mod00_demo PRIVATE mod00_hello course_warnings)

add_executable(mod00_tests tests/test_hello.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod00_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod00_tests PRIVATE mod00_hello course_warnings)

course_add_test(mod00_tests)
