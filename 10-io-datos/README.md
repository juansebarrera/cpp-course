# Modulo 10 - Ficheros, streams y datos

## Objetivos

- Leer y escribir texto con `std::ifstream`/`std::ofstream`.
- Procesar linea a linea con `std::getline`.
- Parsear campos y convertir con `std::stoi`.
- Usar `std::filesystem` para rutas y ficheros temporales.
- Disenar un formato simple (CSV) y documentar sus limitaciones.

## Contenido

| Archivo | Rol |
|---|---|
| `include/io/csv.hpp` | `Contact` y API `read_csv`/`write_csv` |
| `src/csv.cpp` | parseo, escritura, manejo de errores |
| `src/main.cpp` | escribe y relee `contacts_demo.csv` |
| `tests/test_csv.cpp` | round-trip, vacio, fichero inexistente, linea mala |

## Formato

```
name,email,age
Ana,ana@example.com,28
```

Limitaciones conocidas (documentadas a proposito):

- No soporta comas dentro de los campos (haría falta entrecomillado CSV real).
- No soporta saltos de linea dentro de un campo.
- La primera linea se asume cabecera y se ignora.

## Puntos clave

```cpp
std::ifstream input(path);                  // abre en modo lectura
if (!input) throw std::runtime_error(...);  // comprobar apertura
while (std::getline(input, line)) { ... }   // linea a linea
std::ofstream output(path, std::ios::trunc); // sobrescribe
```

- `input` y `output` cierran solos al salir de scope (RAII).
- `line.back() == '\r'` se elimina para tolerar ficheros CRLF.
- Escribe siempre con `'\n'` en el fichero: el control de fin de linea del repo
  es `.gitattributes`, no el stream.

## Ejecutar

```powershell
cmake --build build --target mod10_demo mod10_tests
ctest --test-dir build -R mod10 --output-on-failure
.\build\10-io-datos\mod10_demo.exe
```

## Ejercicios

En `ejercicios/README.md`:

1. Formato TSV (tabuladores) reutilizando la estructura.
2. Cabecera opcional y deteccion de columnas por nombre.
3. Estadisticas del CSV: numero de contactos, edad media, dominio mas comun.
4. Agenda persistente: cargar al inicio, guardar al salir.
5. Escritura atomica: escribir a `.tmp` y renombrar con `std::filesystem::rename`.

## Criterios de entrega

- `ctest --test-dir build -R mod10` en verde.
- Tests que usen `std::filesystem::temp_directory_path()` y limpien el fichero.
- Errores de apertura y formato lanzan excepciones con mensaje util.

Tag al hacer merge: `v0.10`.
