# Modulo 09 - Errores y robustez

## Objetivos

- Elegir entre valor de retorno, `std::optional` y excepciones.
- Usar `std::optional` para "puede no haber resultado".
- Definir excepciones propias derivadas de `std::runtime_error`.
- Capturar por `const&` y no abusar de `catch (...)`.
- Conocer `std::expected` (C++23) como evolución de `optional` con motivo de error.

## Contenido

| Archivo | Rol |
|---|---|
| `include/err/err.hpp` | `parse_int`, `DivisionError`, `checked_div` |
| `src/err.cpp` | validacion y lanzamiento de excepciones |
| `src/main.cpp` | demo de ambos estilos |
| `tests/test_err.cpp` | entradas invalidas y captura por jerarquia |

## Cuando usar cada mecanismo

| Situacion | Herramienta |
|---|---|
| "No hay resultado" y es normal | `std::optional<T>` |
| Error grave o irrecuperable | excepcion |
| Error esperado que hay que propagar con contexto | `std::expected<T, E>` (C++23) |
| API que no puede lanzar (rendimiento, `noexcept`) | codigo de error / `optional` |

```cpp
std::optional<int> parse_int(const std::string& text);  // no lanza

class DivisionError : public std::runtime_error { ... };
int checked_div(int, int);                              // lanza si denominador == 0
```

- `std::stoi` lanza `std::invalid_argument`/`std::out_of_range`: se captura y se
  convierte en `nullopt`.
- Validar `consumed == text.size()` evita aceptar `"12abc"`.
- `DivisionError` hereda de `runtime_error`, asi que tambien se captura como
  `std::exception` (util para fronteras del programa).

## Ejecutar

```powershell
cmake --build build --target mod09_demo mod09_tests
ctest --test-dir build -R mod09 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. `std::optional<double> parse_double(const std::string&)`.
2. `parse_range` que devuelva `std::pair<int,int>` o `nullopt` si el formato es
   `"a-b"` invalido.
3. Jerarquia `AppError` -> `ValidationError`, `NotFoundError`.
4. Agenda v3 que lance `NotFoundError` al buscar un contacto inexistente.
5. Migra `parse_int` a `std::expected<int, ParseError>` si compilas con C++23
   (GCC 16 soporta `<expected>` aunque no `import std`).

## Criterios de entrega

- `ctest --test-dir build -R mod09` en verde.
- Ningun `catch (...)` sin justificar.
- Los tests de excepciones comprueban el tipo concreto y el mensaje.

Tag al hacer merge: `v0.09`.
