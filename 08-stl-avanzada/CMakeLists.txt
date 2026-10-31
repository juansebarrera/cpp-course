add_library(mod08_stlav src/stlav.cpp)
target_include_directories(mod08_stlav PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod08_stlav PRIVATE course_warnings)

add_executable(mod08_demo src/main.cpp)
target_link_libraries(mod08_demo PRIVATE mod08_stlav course_warnings)

add_executable(mod08_tests tests/test_stlav.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod08_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod08_tests PRIVATE mod08_stlav course_warnings)

course_add_test(mod08_tests)
