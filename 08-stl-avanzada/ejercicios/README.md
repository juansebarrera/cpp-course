# Ejercicios - Modulo 08 (STL avanzada)

## 01 - Conteo de palabras normalizado

```cpp
std::map<std::string, int> count_words(const std::string& text);
```

- Pasa cada palabra a minusculas (`std::tolower` con `unsigned char`).
- Elimina puntuacion (`std::ispunct`).
- Ignora cadenas vacias.

## 02 - Top N

```cpp
std::vector<std::pair<std::string, int>> top_n(const std::map<std::string, int>& counts,
                                               std::size_t n);
```

Copia a un vector y ordena por valor descendente; desempata por clave ascendente.

## 03 - Indice inverso

```cpp
std::map<std::string, std::vector<int>> build_index(const std::vector<std::string>& lines);
```

Guarda en que lineas (empezando en 0) aparece cada palabra.

## 04 - Agenda con map

Cambia la agenda v1 para usar:

```cpp
std::map<std::string, Contact> contacts;  // clave: nombre
```

Implementa `find` con `.find()` y `remove` con `.erase()`. Compara el codigo con
la version con `vector`.

## 05 - map_filter sin std::function

Reescribe:

```cpp
template <typename Transform, typename Predicate>
std::vector<int> map_filter(const std::vector<int>& values, Transform transform,
                            Predicate keep);
```

Mide si cambia algo en legibilidad y explica ventajas/inconvenientes frente a
`std::function`.
