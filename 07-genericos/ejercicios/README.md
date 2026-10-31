# Ejercicios - Modulo 07 (Genericos)

## 01 - max_of generico

```cpp
template <typename T>
std::optional<T> max_of(const std::vector<T>& values);
```

Devuelve `std::nullopt` si el vector esta vacio. Prueba con `int`, `double` y
`std::string` (el orden lexicografico ya existe).

## 02 - Pair

```cpp
template <typename A, typename B>
struct Pair {
    A first;
    B second;
    bool operator==(const Pair&) const = default;
};
```

Verifica con `CHECK(gen::Pair<int, std::string>{1, "a"} == gen::Pair<int, std::string>{1, "a"})`.

## 03 - unique generico

```cpp
template <typename T>
std::vector<T> unique_keep_order(const std::vector<T>& values);
```

Implementalo con `std::find` y `push_back`. Prueba con `int` y `std::string`.

## 04 - Stack

```cpp
template <typename T>
class Stack {
public:
    void push(T value);
    std::optional<T> pop();
    const T* top() const;
    bool empty() const;
    std::size_t size() const;
};
```

Internamente `std::vector<T>`. `pop` devuelve `nullopt` si esta vacia.

## 05 - Concepts

```cpp
#include <concepts>

template <std::totally_ordered T>
T clamp_value(const T& value, const T& low, const T& high);
```

Crea un `struct SinOrden {}` y comprueba que el compilador da un error claro al
instanciar `clamp_value(SinOrden{...}, ...)`. Copia parte del mensaje en el
README.
