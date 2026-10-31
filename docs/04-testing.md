# 04 - Testing del curso

## Niveles

1. **Modulos 00-10**: mini framework propio (`tests/mini_test.hpp`), sin
   dependencias externas. Ensenya como funciona CTest y que es una asercion.
2. **Modulo 11**: Catch2 v3 opcional mediante `FetchContent`, mas ejecucion
   desde CTest y desde la terminal.

## Mini framework

Escribir un test:

```cpp
#include "mini_test.hpp"
#include "fund/fund.hpp"

TEST_CASE(add_suma_enteros) {
    CHECK_EQ(fund::add(2, 3), 5);
    CHECK_EQ(fund::add(-2, 2), 0);
}

TEST_CASE(clamp_limita_el_rango) {
    CHECK_EQ(fund::clamp(15, 0, 10), 10);
    CHECK_EQ(fund::clamp(-1, 0, 10), 0);
    CHECK_EQ(fund::clamp(5, 0, 10), 5);
}
```

- `TEST_CASE(nombre)` registra la funcion automaticamente.
- `CHECK(cond)` falla el test si la condicion es falsa.
- `CHECK_EQ(a, b)` compara e informa archivo y linea.
- Cada ejecutable de test tiene su propio `main` (ver `tests/mini_test_main.cpp`).

## Comandos

```powershell
ctest --test-dir build --output-on-failure          # todos los tests
ctest --test-dir build -R mod04                     # solo un modulo
ctest --test-dir build -V                            # salida detallada
.\build\04-stl-secuencial\mod04_tests.exe            # un ejecutable directo
```

Salida esperada:

```
[ OK ] add_suma_enteros
[ OK ] clamp_limita_el_rango
2/2 tests passed
```

## Catch2 (modulo 11)

```powershell
cmake -B build -G Ninja -DCPP_COURSE_CATCH2_DEMO=ON
cmake --build build
ctest --test-dir build -R "mean|median" --output-on-failure
```

`catch_discover_tests` registra cada `TEST_CASE` con su nombre, asi que el
filtro usa el texto del caso (no `catch2`). Para ver los nombres:
`ctest --test-dir build -N`.

El primer configure descarga Catch2 (necesita red). Con la opcion en `OFF`
(por defecto) el proyecto no requiere conexion.

## Buenas practicas

- Un test = un comportamiento; nombres descriptivos.
- Cubre casos limite: vacio, cero, negativos, valores maximos.
- Los tests deben ser independientes y reproducibles (sin depender del orden).
- Prueba primero el fallo (test rojo), luego implementa (test verde).
- No modifiques un test para que pase: arregla el codigo o el test esta mal
  planteado.
