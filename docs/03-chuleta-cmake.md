# 03 - Chuleta de CMake

## Comandos

```powershell
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug   # configurar
cmake --build build                                # compilar
ctest --test-dir build --output-on-failure         # tests
cmake --build build --target mod04_demo            # un solo target
cmake --build build --clean-first                  # limpieza + build
cmake --fresh -B build -G Ninja                    # configurar desde cero
```

Opciones utiles del proyecto:

```powershell
cmake -B build -G Ninja -DCPP_COURSE_WERROR=ON     # warnings como errores
cmake -B build -G Ninja -DCPP_COURSE_CATCH2_DEMO=ON # demo de Catch2 (modulo 11)
```

## Estructura de un modulo

```cmake
add_library(mod04_stlsec src/stlsec.cpp)
target_include_directories(mod04_stlsec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(mod04_stlsec PRIVATE course_warnings)

add_executable(mod04_demo src/main.cpp)
target_link_libraries(mod04_demo PRIVATE mod04_stlsec course_warnings)

add_executable(mod04_tests
    tests/test_stlsec.cpp
    ${PROJECT_SOURCE_DIR}/tests/mini_test_main.cpp)
target_include_directories(mod04_tests PRIVATE ${PROJECT_SOURCE_DIR}/tests)
target_link_libraries(mod04_tests PRIVATE mod04_stlsec course_warnings)

course_add_test(mod04_tests)
```

## Conceptos clave

| Concepto | Que hace |
|---|---|
| `add_library` | crea una biblioteca (el codigo reutilizable del modulo) |
| `add_executable` | crea un programa |
| `target_link_libraries` | une dependencias (`PUBLIC` propaga, `PRIVATE` no) |
| `target_include_directories` | directorios de `#include` |
| `target_compile_options` | flags del compilador |
| `enable_testing` + `add_test` | integra los tests con CTest |
| `CMAKE_EXPORT_COMPILE_COMMANDS` | genera `compile_commands.json` para IntelliSense |

## Flags por compilador

El proyecto define el target `course_warnings`:

- GCC/Clang: `-Wall -Wextra -Wpedantic -Wshadow`
- MSVC: `/W4 /permissive- /utf-8`

Enlazalo a cada target con `target_link_libraries(<target> PRIVATE course_warnings)`.

## Anadir un modulo nuevo

1. Crea la carpeta `13-mi-modulo/` con `include/`, `src/`, `tests/`.
2. Copia el `CMakeLists.txt` de otro modulo y ajusta nombres.
3. Anade `13-mi-modulo` a `CPP_COURSE_MODULES` en el `CMakeLists.txt` raiz.
4. Reconfigura: `cmake -B build -G Ninja`.

## Generadores

| Generador | Cuando usarlo |
|---|---|
| `Ninja` | rapido, ideal en Windows con MinGW (recomendado) |
| `MinGW Makefiles` | alternativa si Ninja falla |
| `Visual Studio 17 2022` | si usas MSVC en Windows |
| `Unix Makefiles` | Linux/macOS por defecto |
