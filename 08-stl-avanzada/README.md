# Modulo 08 - STL asociativa y lambdas

## Objetivos

- Usar `std::map` (claves ordenadas) y conocer `std::unordered_map`.
- Recorrer con structured bindings: `for (const auto& [key, value] : m)`.
- Escribir lambdas y capturarlas correctamente (`[&]`, `[=]`, por valor concreto).
- Pasar funciones como parametro con `std::function`.
- Componer "transformar y filtrar" sin bucles anidados.

## Contenido

| Archivo | Rol |
|---|---|
| `include/stlav/stlav.hpp` | frecuencias, claves, map+filter |
| `src/stlav.cpp` | `std::map`, lambdas, `std::function` |
| `src/main.cpp` | frecuencias de palabras y pipeline |
| `tests/test_stlav.cpp` | conteo, orden y filtros |

## Puntos clave

```cpp
std::map<std::string, int> counts;
++counts[word];                       // inserta con 0 si no existe

for (const auto& [word, count] : counts) { /* ... */ }

std::function<int(int)> transform;
std::function<bool(int)> keep;
```

- `std::map` ordena por clave; `std::unordered_map` es mas rapido si el orden
  no importa (coste: hash).
- `counts.at(key)` lanza excepcion si falta; `counts[key]` crea la clave.
- Captura lambdas por referencia solo mientras las referencias vivan; si la
  lambda se guarda para despues, captura por valor.
- `(void)count;` silencia el aviso de variable no usada en el structured binding.

## Ejecutar

```powershell
cmake --build build --target mod08_demo mod08_tests
ctest --test-dir build -R mod08 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. Contar palabras de un texto real ignorando mayusculas y puntuacion.
2. Top 3 de palabras mas frecuentes (ordenar el map por valor).
3. Indice inverso: palabra -> conjunto de lineas donde aparece.
4. Agenda v1 con `std::map<std::string, Contact>` (busqueda O(log n)).
5. Sustituye `std::function` por plantillas en `map_filter` y compara.

## Criterios de entrega

- `ctest --test-dir build -R mod08` en verde.
- Tests con mapa vacio y claves repetidas.
- No usar `operator[]` sobre un `const map`: debe ser `.at()` o `.find()`.

Tag al hacer merge: `v0.08`.
