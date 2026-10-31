# Modulo 11 - Calidad: tests, debug y CI

## Objetivos

- Organizar tests con CTest y separar casos por target.
- Conocer un framework real: Catch2 v3 via `FetchContent`.
- Depurar con GDB desde VS Code y desde terminal.
- Detectar errores con sanitizers (ASan/UBSan) donde esten disponibles.
- Entender el pipeline de CI: configure -> build -> test.

## Contenido

| Archivo | Rol |
|---|---|
| `include/cal/stats.hpp` | `mean`, `median`, `variance` |
| `src/stats.cpp` | implementacion con `<algorithm>` |
| `tests/test_stats.cpp` | tests con el mini framework |
| `tests/catch2_demo.cpp` | mismos casos con Catch2 (opcional) |

## Ejecutar

```powershell
# tests del curso
cmake --build build --target mod11_demo mod11_tests
ctest --test-dir build -R mod11 --output-on-failure

# Catch2 (descarga en el primer configure)
cmake -B build -G Ninja -DCPP_COURSE_CATCH2_DEMO=ON
cmake --build build
ctest --test-dir build -R "mean|median" --output-on-failure
```

`catch_discover_tests` nombra cada test con el texto del `TEST_CASE`, no con el
nombre del target: por eso el filtro es `mean|median`, no `catch2`.

## Catch2 en 20 segundos

```cpp
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

TEST_CASE("nombre del caso", "[tag]") {
    REQUIRE(cal::mean({1.0, 2.0, 3.0}) == Catch::Approx(2.0));
}
```

- `REQUIRE` aborta el caso si falla; `CHECK` continua.
- `Catch::Approx` resuelve la comparacion de `double`.
- `catch_discover_tests` registra cada `TEST_CASE` como test de CTest.

## Depuracion

- `F5` en VS Code (configuracion ya preparada en `.vscode/launch.json`).
- Por terminal: `gdb .\build\11-calidad\mod11_tests.exe`, `b main`, `run`, `bt`.
- Otros comandos y ejemplos: [docs/02-debug-gdb.md](../docs/02-debug-gdb.md).

## Sanitizers

En este MinGW no hay `libasan` (probado: `cannot find -lasan`). Usa WSL/Ubuntu o
clang:

```bash
g++ -std=c++20 -g -fsanitize=address,undefined -fno-omit-frame-pointer -I include \
    src/stats.cpp tests/test_stats.cpp -o stats_asan
./stats_asan
```

## Ejercicios

En `ejercicios/README.md`:

1. Lleva `median` a un caso donde reciba vector vacio, uno y dos elementos; cubre
   con tests.
2. Escribe un test que falle a proposito y observa el reporte de CTest.
3. Mide cobertura con `gcov`/`llvm-cov` (opcional) e identifica lineas sin cubrir.
4. Anade un job de CI con `-DCPP_COURSE_WERROR=ON`.
5. Ejecuta los tests bajo ASan y arregla cualquier hallazgo.

## Criterios de entrega

- `ctest --test-dir build` en verde en local y en CI.
- Ningun test depende del orden de ejecucion.
- El README documenta como depurar y como correr sanitizers.

Tag al hacer merge: `v0.11`.
