# Ejercicios - Modulo 02 (Funciones)

Crea un archivo por ejercicio en `ejercicios/` (por ejemplo `ej01_conversor.cpp`)
y compilalos a mano:

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic ejercicios\ej01_conversor.cpp -o ej01.exe
.\ej01.exe
```

## 01 - Conversor de unidades

```cpp
double km_to_miles(double km);
double celsius_to_fahrenheit(double celsius);
```

Imprime una tabla de 0 a 100 km cada 10 y de -40 a 100 C cada 20.
Anade los tests correspondientes en `tests/`.

## 02 - Numeros primos

```cpp
bool is_prime(int n);
int count_primes(int limit);
```

`is_prime` debe devolver `false` para 0, 1 y negativos.
Optimiza: solo comprueba divisores hasta `i * i <= n`.

## 03 - Invertir una cadena

```cpp
std::string reverse_copy(const std::string& text);
void reverse_in_place(std::string& text);
```

La primera no debe modificar la entrada (compruebalo con un test).

## 04 - Fibonacci

```cpp
long long fib_iterative(int n);
long long fib_recursive(int n);
```

Compara tiempos para `n = 35` con `std::chrono`. Explica en un comentario por
que la recursiva es mas lenta. No la uses con `n > 40`.

## 05 - Calculadora con funciones

Implementa `add`, `sub`, `mul`, `div` (con validacion de division por cero) y un
menu en `main` con `switch`. Devuelve un codigo de error distinto de cero ante
entradas invalidas.
