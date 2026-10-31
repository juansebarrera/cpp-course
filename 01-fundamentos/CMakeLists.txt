add_library(mod01_fund src/fund.cpp)
target_include_directories(mod01_fund PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod01_fund PRIVATE course_warnings)

add_executable(mod01_demo src/main.cpp)
target_link_libraries(mod01_demo PRIVATE mod01_fund course_warnings)

add_executable(mod01_tests tests/test_fund.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod01_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod01_tests PRIVATE mod01_fund course_warnings)

course_add_test(mod01_tests)
