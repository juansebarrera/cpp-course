# Modulo 03 - Modularidad y CMake

## Objetivos

- Separar declaracion (`.hpp`) e implementacion (`.cpp`).
- Entender `#pragma once`, inclusiones y la regla de definicion unica (ODR).
- Organizar una biblioteca con `include/` y `src/`.
- Escribir un `CMakeLists.txt` con `add_library`/`add_executable`.
- Conocer los flags de warnings y por que activarlos.

## Contenido

| Archivo | Rol |
|---|---|
| `include/units/units.hpp` | API publica |
| `src/units.cpp` | implementacion |
| `src/main.cpp` | demo (`mod03_demo`) |
| `tests/test_units.cpp` | tests con comparacion de `double` |

## Reglas de oro

1. Las cabeceras declaran; los `.cpp` definen. Definir funciones en una
   cabecera incluida por varios `.cpp` provoca errores de enlace.
2. Usa `#pragma once` (o include guards) en cada cabecera.
3. Incluye en el `.cpp` primero su propia cabecera: detecta dependencias
   ocultas.
4. Nunca compares `double` con `==`; usa un epsilon (`almost_equal`).
5. `-Wall -Wextra -Wpedantic -Wshadow` siempre; `-Werror` en CI.

## Como se compila este modulo

```powershell
cmake --build build --target mod03_demo mod03_tests
ctest --test-dir build -R mod03 --output-on-failure
```

La biblioteca `mod03_units` se compila una vez y la usan la demo y los tests.
Cambiar `src/main.cpp` no recompila `units.cpp`.

## Ejercicios

En `ejercicios/README.md`:

1. Anade `celsius_to_kelvin` y `kelvin_to_celsius` con tests.
2. Mueve `almost_equal` a una cabecera propia `include/units/math_utils.hpp`.
3. Crea una biblioteca nueva `mod03_geometry` con `area_circle` y `area_rect`.
4. Rompe a proposito la ODR (define una funcion en la cabecera) y lee el error
   del enlazador; documenta el mensaje.
5. Activa `-Wconversion` y corrige los avisos que aparezcan.

## Criterios de entrega

- `ctest --test-dir build -R mod03` en verde.
- Build limpio con `-DCPP_COURSE_WERROR=ON`.
- El README explica que hace cada target de CMake.

Tag al hacer merge: `v0.03`.
