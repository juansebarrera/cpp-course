# Ejercicios - Modulo 04 (STL secuencial)

## 01 - Estadisticas

```cpp
double mean(const std::vector<double>& values);
double min_value(const std::vector<double>& values);
double max_value(const std::vector<double>& values);
double stddev(const std::vector<double>& values);
```

Decide y documenta que pasa con un vector vacio. Anade tests.

## 02 - Palabras repetidas

Dado un `std::string` con palabras separadas por espacios, devuelve un
`std::vector<std::string>` con las que aparecen mas de una vez, sin duplicados.

Pista: `std::find`, `std::count` (cabecera `<algorithm>`).

## 03 - Eliminar duplicados

```cpp
std::vector<int> unique_keep_order(const std::vector<int>& values);
```

Usa `std::find` sobre el resultado. No uses `std::set` (modulo 08).

## 04 - Rotar

```cpp
std::vector<int> rotate_copy(const std::vector<int>& values, std::size_t k);
```

Usa `std::rotate` sobre una copia. Normaliza `k` con `k % size()` y evita
dividir por cero con vector vacio.

## 05 - Agenda v1

Crea `struct Contact { std::string name; std::string email; }` y un
`std::vector<Contact>` en `main`:

- anadir contacto,
- listar todos,
- buscar por nombre exacto,
- eliminar el ultimo.

Este es el punto de partida del proyecto acumulativo.
