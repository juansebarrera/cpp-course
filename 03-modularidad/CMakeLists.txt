add_library(mod03_units src/units.cpp)
target_include_directories(mod03_units PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod03_units PRIVATE course_warnings)

add_executable(mod03_demo src/main.cpp)
target_link_libraries(mod03_demo PRIVATE mod03_units course_warnings)

add_executable(mod03_tests tests/test_units.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod03_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod03_tests PRIVATE mod03_units course_warnings)

course_add_test(mod03_tests)
