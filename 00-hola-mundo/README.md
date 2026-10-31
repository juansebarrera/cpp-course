# Modulo 00 - Hola mundo y entorno

## Objetivos

- Compilar y ejecutar un programa C++ con `g++` y con CMake.
- Entender el ciclo: cabecera (`.hpp`) -> implementacion (`.cpp`) -> `main`.
- Ejecutar los tests con CTest.
- Publicar el repositorio en GitHub.

## Contenido

| Archivo | Rol |
|---|---|
| `include/hello/hello.hpp` | declara `hello::greeting()` |
| `src/hello.cpp` | implementa la funcion |
| `src/main.cpp` | programa de consola que la usa |
| `tests/test_hello.cpp` | dos tests con el mini framework del curso |

## Pasos

```powershell
# 1. Compilar a mano (sin CMake)
g++ -std=c++20 -Wall -Wextra -Wpedantic src/main.cpp src/hello.cpp -I include -o hello.exe
.\hello.exe

# 2. Compilar todo el repo con CMake
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

Salida esperada de `mod00_demo`:

```
Hola, C++!
Compilado con C++202002
```

Salida esperada de `ctest`: `100% tests passed, 0 tests failed out of 1`
(el ejecutable de tests agrupa los dos casos).

## Ejercicios

1. Cambia el saludo y actualiza el test (deben seguir pasando).
2. Anade `std::string greeting(const std::string& name)` que devuelva
   `"Hola, <name>!"` y un test para ella.
3. Compila con `-DCPP_COURSE_WERROR=ON` y corrige cualquier warning.
4. Lanza el debugger con `F5` y pon un breakpoint en `main`.

## Entrega

```powershell
git switch -c modulo-00
git add .
git commit -m "feat(mod00): entorno, hola mundo y primer test"
git push -u origin modulo-00
gh pr create --fill
```

Tag al hacer merge: `v0.00`.
