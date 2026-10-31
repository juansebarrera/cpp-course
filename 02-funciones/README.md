# Modulo 02 - Funciones

## Objetivos

- Declarar, definir y llamar funciones.
- Paso por valor vs paso por referencia (`&`).
- Sobrecarga de funciones y `const` en parametros.
- Devolver por valor y entender `std::string`/`std::vector` como tipos de la STL.
- Usar `std::toupper` con el cast correcto (`unsigned char`).

## Contenido

| Archivo | Rol |
|---|---|
| `include/func/func.hpp` | API del modulo |
| `src/func.cpp` | implementaciones |
| `src/main.cpp` | demo de cada funcion |
| `tests/test_func.cpp` | 9 comprobaciones |

## Puntos clave

```cpp
void swap_values(int& a, int& b);       // modifica los originales
int max_of(int a, int b);               // copia (no modifica)
int max_of(int a, int b, int c);        // sobrecarga
int sum(const std::vector<int>& values); // const& evita copia y no modifica
```

Regla practica: parametros grandes -> `const&`; parametros que deben cambiar ->
`&`; tipos pequenos (`int`, `double`, punteros) -> por valor.

## Ejecutar

```powershell
cmake --build build --target mod02_demo mod02_tests
ctest --test-dir build -R mod02 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. Conversor de unidades con funciones puras (`km_to_miles`, `c_to_f`).
2. `bool is_prime(int n)` y contador de primos hasta `N`.
3. `std::string reverse(const std::string&)` sin modificar la original.
4. Serie de Fibonacci con tres variantes: iterativa, recursiva y con memo.
5. Calculadora con funciones `add`, `sub`, `mul`, `div` y un `switch` en `main`.

## Criterios de entrega

- `ctest --test-dir build -R mod02` en verde.
- Sin warnings (`-DCPP_COURSE_WERROR=ON`).
- Cada funcion nueva tiene al menos un test propio.

Tag al hacer merge: `v0.02`.
