# Ejercicios - Modulo 05 (Memoria y RAII)

## 01 - resize

```cpp
void resize(std::size_t new_size);
```

Conserva los `min(size_viejo, new_size)` primeros valores y rellena con cero los
nuevos. Implementalo con un buffer temporal y `std::copy`. Anade tests.

## 02 - unique_ptr vs shared_ptr

Escribe dos versiones de una clase `Playlist` que guarda canciones:

- version A: `std::vector<Song>` por valor,
- version B: `std::vector<std::shared_ptr<Song>>`.

Responde en un comentario: que gana cada una en claridad y en propiedad.

## 03 - Estudiantes

```cpp
struct Student {
    std::string name;
    std::vector<int> grades;
};
double average(const std::vector<Student>& students);
```

Recibe por `const&`, no copies el vector dentro de la funcion.

## 04 - Fuga intencionada

En un programa de prueba, reserva con `new` y no liberes. Ejecuta bajo
AddressSanitizer (WSL/Ubuntu o clang):

```bash
g++ -g -fsanitize=address fuga.cpp -o fuga && ./fuga
```

Copia el mensaje de LeakSanitizer y explica cada linea.

## 05 - Reemplaza IntBuffer por std::vector

Reescribe `IntBuffer` usando `std::vector<int>` como miembro. Compara lineas de
codigo antes/despues y anota que funciones ya no necesitas escribir.
