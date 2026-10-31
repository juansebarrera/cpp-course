add_library(mod11_cal src/stats.cpp)
target_include_directories(mod11_cal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod11_cal PRIVATE course_warnings)

add_executable(mod11_demo src/main.cpp)
target_link_libraries(mod11_demo PRIVATE mod11_cal course_warnings)

add_executable(mod11_tests tests/test_stats.cpp ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod11_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod11_tests PRIVATE mod11_cal course_warnings)

course_add_test(mod11_tests)

option(CPP_COURSE_CATCH2_DEMO "Compilar el demo de Catch2 (requiere red)" OFF)
if(CPP_COURSE_CATCH2_DEMO)
    include(FetchContent)
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.8.1
        GIT_SHALLOW TRUE
    )
    FetchContent_MakeAvailable(Catch2)

    add_executable(mod11_catch2_demo tests/catch2_demo.cpp)
    target_link_libraries(mod11_catch2_demo PRIVATE mod11_cal Catch2::Catch2WithMain
                                                     course_warnings)

    include(Catch)
    catch_discover_tests(mod11_catch2_demo)
endif()
