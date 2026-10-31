add_library(mod12_agenda src/agenda.cpp)
target_include_directories(mod12_agenda PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod12_agenda PRIVATE course_warnings)

add_executable(mod12_agenda_cli src/main.cpp)
target_link_libraries(mod12_agenda_cli PRIVATE mod12_agenda course_warnings)

add_executable(mod12_tests tests/test_agenda.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod12_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod12_tests PRIVATE mod12_agenda course_warnings)

course_add_test(mod12_tests)
