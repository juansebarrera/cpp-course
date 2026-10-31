cmake_minimum_required(VERSION 3.25)

project(cpp_course VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(CPP_COURSE_WERROR "Tratar los warnings como errores" OFF)

add_library(course_warnings INTERFACE)
if(MSVC)
    target_compile_options(course_warnings INTERFACE /W4 /permissive- /utf-8)
    if(CPP_COURSE_WERROR)
        target_compile_options(course_warnings INTERFACE /WX)
    endif()
else()
    target_compile_options(course_warnings INTERFACE -Wall -Wextra -Wpedantic -Wshadow)
    if(CPP_COURSE_WERROR)
        target_compile_options(course_warnings INTERFACE -Werror)
    endif()
endif()

enable_testing()

function(course_add_test target)
    add_test(NAME ${target} COMMAND ${target})
endfunction()

set(CPP_COURSE_MODULES
    00-hola-mundo
    01-fundamentos
    02-funciones
    03-modularidad
    04-stl-secuencial
    05-memoria
    06-poo
    07-genericos
    08-stl-avanzada
    09-errores
    10-io-datos
    11-calidad
    12-proyecto-final
)

foreach(module IN LISTS CPP_COURSE_MODULES)
    add_subdirectory(${module})
endforeach()
