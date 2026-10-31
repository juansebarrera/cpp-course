# Ejercicios - Modulo 00 (Entorno)

## 01 - Compila a mano

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic src/main.cpp src/hello.cpp -I include -o hello.exe
.\hello.exe
```

Escribe el comando completo y explica que hace `-I` y `-o`.

## 02 - Cambia el saludo

Modifica `hello::greeting()` para devolver otro texto, actualiza
`tests/test_hello.cpp` y comprueba que `ctest` sigue en verde.

## 03 - Sobrecarga de saludo

Anade:

```cpp
std::string greeting(const std::string& name);
```

Devuelve `"Hola, <name>!"`. Anade un test con `"Ana"`.

## 04 - Warnings como errores

```powershell
cmake -B build -G Ninja -DCPP_COURSE_WERROR=ON
cmake --build build
```

Provoca un warning a proposito (variable sin usar) y comprueba que el build falla.
Corrigelo.

## 05 - Debug

Abre VS Code, pulsa `F5`, pon un breakpoint en `main` y ejecuta paso a paso con
`F10`. Anota los valores de `__cplusplus` y del saludo en el panel VARIABLES.
