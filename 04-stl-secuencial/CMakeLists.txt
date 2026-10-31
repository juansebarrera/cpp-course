add_library(mod04_stlsec src/stlsec.cpp)
target_include_directories(mod04_stlsec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod04_stlsec PRIVATE course_warnings)

add_executable(mod04_demo src/main.cpp)
target_link_libraries(mod04_demo PRIVATE mod04_stlsec course_warnings)

add_executable(mod04_tests tests/test_stlsec.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod04_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod04_tests PRIVATE mod04_stlsec course_warnings)

course_add_test(mod04_tests)
