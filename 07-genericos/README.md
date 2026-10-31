# Modulo 07 - Programacion generica

## Objetivos

- Escribir plantillas de funcion (`template <typename T>`).
- Escribir plantillas de clase (`Box<T>`).
- Entender instanciacion implicita y deduccion de tipos.
- Usar `auto`, `const&` y `std::move` en contexto generico.
- Conocer la diferencia entre cabecera y `.cpp` en plantillas.

## Contenido

| Archivo | Rol |
|---|---|
| `include/gen/gen.hpp` | `clamp_value<T>`, `Box<T>`, `sum_all<T>` |
| `src/main.cpp` | uso con `int`, `double` y `std::string` |
| `tests/test_gen.cpp` | varias instanciaciones |

Este modulo es **header-only**: `mod07_gen` es una biblioteca `INTERFACE`, no
compila un `.cpp`. Las plantillas deben estar visibles donde se usan.

## Puntos clave

```cpp
template <typename T>
T clamp_value(const T& value, const T& low, const T& high);

gen::Box<std::string> box("C++");   // instanciacion explicita
gen::clamp_value(15, 0, 10);        // T deducido como int
```

- Si la plantilla necesitara estado compartido, se puede separar en `.hpp` +
  `.tpp` incluido al final de la cabecera.
- Un error de plantilla suele aparecer en la instanciacion, no en la definicion:
  lee el mensaje desde la ultima linea hacia arriba.
- `T total{}` inicializa a cero para tipos aritmeticos y a su valor por defecto
  para clases, sin asumir `T(0)`.

## Ejecutar

```powershell
cmake --build build --target mod07_demo mod07_tests
ctest --test-dir build -R mod07 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. `template <typename T> T max_of(const std::vector<T>&)`, con `std::optional`
   para vector vacio.
2. `Pair<A, B>` con `first`, `second` y `operator==` por defecto.
3. `template <typename T> std::vector<T> unique_keep_order(const std::vector<T>&)`.
4. Un `Stack<T>` con `push`, `pop`, `top`, `empty` usando `std::vector<T>`.
5. Anade un `concept` sencillo (`std::totally_ordered`) a `clamp_value` y prueba
   que un tipo sin `<` da un error claro.

## Criterios de entrega

- `ctest --test-dir build -R mod07` en verde.
- Al menos dos instanciaciones por plantilla (por ejemplo `int` y `std::string`).
- El README explica por que no hay `gen.cpp`.

Tag al hacer merge: `v0.07`.
