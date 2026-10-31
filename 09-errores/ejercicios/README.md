# Ejercicios - Modulo 09 (Errores)

## 01 - parse_double

```cpp
std::optional<double> parse_double(const std::string& text);
```

Mismas reglas que `parse_int`: rechaza texto vacio, restos no consumidos y
valores fuera de rango. Anade tests con `"3.14"`, `"-0.5"`, `"1e3"` y `"nan"`.

## 02 - Rango

```cpp
std::optional<std::pair<int, int>> parse_range(const std::string& text);
```

Formato `"a-b"` con `a <= b`. Rechaza `"5-2"`, `"a-b"`, `"1-"` y `""`.

## 03 - Jerarquia de errores

```cpp
class AppError : public std::runtime_error { ... };
class ValidationError : public AppError { ... };
class NotFoundError : public AppError { ... };
```

Demuestra con tests que capturar `AppError` captura tambien las derivadas.

## 04 - Agenda v3

```cpp
Contact Agenda::get(const std::string& name) const;  // lanza NotFoundError
```

Mantén `find` devolviendo `optional` y anade `get` que lanza. Documenta cuando
usar cada una.

## 05 - std::expected

Con `-std=c++23`:

```cpp
enum class ParseError { empty, invalid, out_of_range };

std::expected<int, ParseError> parse_int_expected(const std::string& text);
```

Comprueba `has_value()`, `value()` y `error()`. Compara el codigo con la version
`optional`: que informacion gana el llamador.
