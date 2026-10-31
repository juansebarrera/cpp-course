# Ejercicios - Modulo 03 (Modularidad)

## 01 - Kelvin

Anade a `units`:

```cpp
double celsius_to_kelvin(double celsius);
double kelvin_to_celsius(double kelvin);
```

Rechaza temperaturas bajo cero absoluto devolviendo `0.0` o documentando el
comportamiento. Anade tests para `-273.15 C`, `0 C` y `100 C`.

## 02 - Cabecera de utilidades

Mueve `almost_equal` a `include/units/math_utils.hpp`. Actualiza los `#include`
y comprueba que todo sigue compilando y los tests pasan.

## 03 - Biblioteca de geometria

Crea `mod03_geometry` como biblioteca nueva:

```cpp
double area_circle(double radius);
double area_rectangle(double width, double height);
double area_triangle(double base, double height);
```

Registrala en el `CMakeLists.txt` del modulo y crea su ejecutable de tests.

## 04 - Rompe la ODR a proposito

Define una funcion no-`inline` completa dentro de una cabecera, incluyela en dos
`.cpp` y observa el error del enlazador (`multiple definition of ...`).
Corrigelo y escribe en `docs/` un parrafo explicando que paso.

## 05 - Warnings estrictos

Configura con `-Wconversion -Wsign-conversion` (GCC) y corrige los avisos.
Presta atencion a las conversiones entre `int`, `std::size_t` y `double`.
