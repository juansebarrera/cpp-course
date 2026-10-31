add_library(mod07_gen INTERFACE)
target_include_directories(mod07_gen INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod07_gen INTERFACE course_warnings)

add_executable(mod07_demo src/main.cpp)
target_link_libraries(mod07_demo PRIVATE mod07_gen course_warnings)

add_executable(mod07_tests tests/test_gen.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod07_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod07_tests PRIVATE mod07_gen course_warnings)

course_add_test(mod07_tests)
