# Modulo 04 - STL secuencial

## Objetivos

- Usar `std::vector` y `std::string` con soltura.
- Recorrer con bucles `for` basados en rango e iteradores.
- Aplicar algoritmos de `<algorithm>`: `std::sort`, `std::copy_if`, `std::find`.
- Acumular con `<numeric>` (`std::accumulate`).
- Entender lambdas basicas y captura por referencia.
- Reservar capacidad (`reserve`) para evitar reubicaciones.

## Contenido

| Archivo | Rol |
|---|---|
| `include/stlsec/stlsec.hpp` | filtrado, orden, suma, busqueda |
| `src/stlsec.cpp` | implementacion con algoritmos estandar |
| `src/main.cpp` | demo con enteros y cadenas |
| `tests/test_stlsec.cpp` | casos vacios, negativos y orden |

## Puntos clave

```cpp
std::copy_if(v.begin(), v.end(), std::back_inserter(out), pred);
std::sort(v.begin(), v.end(), std::greater<int>());
std::accumulate(v.begin(), v.end(), 0);
word.find(needle) != std::string::npos;
```

- Pasar `std::vector` grande por `const&` evita copias.
- `sorted_desc` recibe el vector **por valor** a proposito: ordena su propia copia.
- Los tests comparan `std::vector` completos: `==` ya esta definido.

## Ejecutar

```powershell
cmake --build build --target mod04_demo mod04_tests
ctest --test-dir build -R mod04 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. Estadisticas: media, min, max y desviacion tipica de un `vector<double>`.
2. Contar palabras de un texto y listar las que aparecen mas de una vez
   (por ahora con `vector`, sin `map`).
3. Eliminar duplicados conservando el orden original.
4. Rotar un vector `k` posiciones con `std::rotate`.
5. Agenda v1: contactos en un `vector`, anadir, listar, buscar por nombre.

## Criterios de entrega

- `ctest --test-dir build -R mod04` en verde.
- Tests que cubran vector vacio, un elemento y negativos.
- Sin bucles con indices donde un rango o un algoritmo sea mas claro.

Tag al hacer merge: `v0.04`.
