add_library(mod09_err src/err.cpp)
target_include_directories(mod09_err PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod09_err PRIVATE course_warnings)

add_executable(mod09_demo src/main.cpp)
target_link_libraries(mod09_demo PRIVATE mod09_err course_warnings)

add_executable(mod09_tests tests/test_err.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod09_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod09_tests PRIVATE mod09_err course_warnings)

course_add_test(mod09_tests)
