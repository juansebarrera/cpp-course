# Modulo 05 - Memoria y RAII

## Objetivos

- Distinguir stack y heap; cuando usar cada uno.
- Entender punteros, referencias y propiedad de recursos.
- Aplicar RAII: el destructor libera lo que el constructor reservo.
- Usar `std::unique_ptr` y conocer `std::shared_ptr`.
- Implementar correctamente copia y movimiento (regla de cero / regla de cinco).
- Evitar fugas con copia y asignacion seguras ante autoasignacion.

## Contenido

| Archivo | Rol |
|---|---|
| `include/mem/mem.hpp` | clase `IntBuffer` con `unique_ptr<int[]>` |
| `src/mem.cpp` | constructor, copia profunda, movimiento, `sum` |
| `src/main.cpp` | demo de copia independiente |
| `tests/test_mem.cpp` | tamano cero, copia, movimiento |

## Idea central

```cpp
class IntBuffer {
    std::unique_ptr<int[]> data_;  // dueno del bloque
    std::size_t size_ = 0;
};
```

- `new int[size]{}` reserva e inicializa a cero.
- El destructor por defecto libera con `delete[]` gracias a `unique_ptr<int[]>`.
- La copia es **profunda**: cada buffer tiene su propio bloque.
- El movimiento transfiere el puntero sin copiar; el origen queda vacio.
- Asignacion por copia y swap: `IntBuffer copy(other); *this = std::move(copy);`
  simplifica y da seguridad ante excepciones.

## Por que no `new`/`delete` a mano

Si entre `new` y `delete` hay un `return` temprano o una excepcion, pierdes la
memoria. RAII ata la liberacion a la vida del objeto.

## Ejecutar

```powershell
cmake --build build --target mod05_demo mod05_tests
ctest --test-dir build -R mod05 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. Anade `resize(std::size_t)` conservando los datos existentes.
2. Implementa `std::shared_ptr<std::vector<int>>` como alternativa y compara.
3. Crea un `Student` con `std::string` y un `std::vector<int>` de notas en un
   `std::vector<Student>` pasado por `const&`.
4. Provoca a proposito una fuga (sin liberar) y detectala con ASan en WSL.
5. Cambia `IntBuffer` a `std::vector<int>` y explica que codigo desaparece.

## Criterios de entrega

- `ctest --test-dir build -R mod05` en verde.
- No hay `new`/`delete` sueltos fuera del constructor.
- Documenta en el README cuando usarias `unique_ptr` vs `shared_ptr`.

Tag al hacer merge: `v0.05`.
