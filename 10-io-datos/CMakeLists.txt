add_library(mod10_io src/csv.cpp)
target_include_directories(mod10_io PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod10_io PRIVATE course_warnings)

add_executable(mod10_demo src/main.cpp)
target_link_libraries(mod10_demo PRIVATE mod10_io course_warnings)

add_executable(mod10_tests tests/test_csv.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod10_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod10_tests PRIVATE mod10_io course_warnings)

course_add_test(mod10_tests)
