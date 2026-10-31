# Modulo 01 - Fundamentos

## Objetivos

- Tipos basicos (`int`, `double`, `bool`, `char`, `std::string`).
- Operadores aritmeticos, comparacion y logica.
- Control de flujo: `if`, `else`, `switch`, `for`, `while`.
- Entrada/salida con `std::cin`, `std::cout`, `std::cerr`.
- Primer contacto con el tipo `std::string`.

## Contenido

| Archivo | Rol |
|---|---|
| `include/fund/fund.hpp` | API: `add`, `clamp`, `is_even`, `describe_age` |
| `src/fund.cpp` | implementacion con `if`/`return` |
| `src/main.cpp` | calculadora CLI que lee dos enteros |
| `tests/test_fund.cpp` | tests de casos normales y limites |

## Ejecutar

```powershell
cmake --build build --target mod01_demo mod01_tests
ctest --test-dir build -R mod01 --output-on-failure
.\build\01-fundamentos\mod01_demo.exe
```

## Ejercicios

En `ejercicios/README.md`:

1. Calculadora completa: suma, resta, multiplicacion, division y modulo con menu
   (`switch`) y validacion de division por cero.
2. Tabla de multiplicar del 1 al 10 con `for` anidados.
3. Contar vocales de una frase usando un `for` sobre `std::string`.
4. Clasificar un numero como positivo/negativo/cero y par/impar.
5. Adivina el numero: bucle `while` con pistas "mayor"/"menor".

## Criterios de entrega

- Todos los tests pasan: `ctest --test-dir build -R mod01`.
- Sin warnings con `-DCPP_COURSE_WERROR=ON`.
- La calculadora no se cae con entradas invalidas.
- README del modulo actualizado con lo aprendido.

Tag al hacer merge: `v0.01`.
