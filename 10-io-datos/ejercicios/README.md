# Ejercicios - Modulo 10 (I/O y datos)

## 01 - TSV

Anade:

```cpp
std::vector<Contact> read_tsv(const std::filesystem::path& path);
void write_tsv(const std::filesystem::path& path, const std::vector<Contact>& contacts);
```

Reutiliza `split` cambiando el separador a `'\t'`. Anade tests de round-trip.

## 02 - Cabecera por nombre

Lee la primera linea, localiza las columnas `name`, `email`, `age` y rellena los
campos en el orden que vengan. Si falta alguna columna, lanza excepcion.

## 03 - Estadisticas

```cpp
struct Report {
    std::size_t total = 0;
    double average_age = 0.0;
    std::string most_common_domain;
};
Report analyze(const std::vector<Contact>& contacts);
```

El dominio es la parte tras `@`. Con vector vacio, `average_age = 0` y dominio
vacio. Tests con 0, 1 y varios contactos.

## 04 - Agenda persistente

Carga `agenda.csv` al arrancar (si no existe, empieza vacia) y guarda al salir.
Anade una opcion "guardar" en el menu y maneja el error de escritura.

## 05 - Escritura atomica

Escribe primero en `path + ".tmp"` y luego:

```cpp
std::filesystem::rename(tmp, path);
```

Comprueba que un fallo a mitad de escritura no deja el fichero original corrupto.
