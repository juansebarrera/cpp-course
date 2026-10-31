add_library(mod02_func src/func.cpp)
target_include_directories(mod02_func PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod02_func PRIVATE course_warnings)

add_executable(mod02_demo src/main.cpp)
target_link_libraries(mod02_demo PRIVATE mod02_func course_warnings)

add_executable(mod02_tests tests/test_func.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod02_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod02_tests PRIVATE mod02_func course_warnings)

course_add_test(mod02_tests)
