add_library(mod06_poo src/poo.cpp)
target_include_directories(mod06_poo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod06_poo PRIVATE course_warnings)

add_executable(mod06_demo src/main.cpp)
target_link_libraries(mod06_demo PRIVATE mod06_poo course_warnings)

add_executable(mod06_tests tests/test_poo.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod06_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod06_tests PRIVATE mod06_poo course_warnings)

course_add_test(mod06_tests)
