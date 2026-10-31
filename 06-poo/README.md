# Modulo 06 - Programacion orientada a objetos

## Objetivos

- Definir clases con estado (`private`) y comportamiento (`public`).
- Constructores, destructores y `explicit`.
- Herencia, `override`, funciones virtuales puras y clases abstractas.
- Polimorfismo con `std::vector<std::unique_ptr<Base>>`.
- Uso de `std::numbers::pi` (C++20) en lugar de constantes magicas.

## Contenido

| Archivo | Rol |
|---|---|
| `include/poo/poo.hpp` | `Shape` abstracta, `Circle`, `Rectangle` |
| `src/poo.cpp` | areas y `total_area` polimorfica |
| `src/main.cpp` | lista heterogenea de figuras |
| `tests/test_poo.cpp` | areas y suma polimorfica |

## Conceptos

```cpp
class Shape {
public:
    virtual ~Shape() = default;       // destructor virtual obligatorio
    virtual double area() const = 0;  // funcion virtual pura
};

class Circle final : public Shape {
public:
    explicit Circle(double radius);   // evita conversiones implicitas
    double area() const override;     // override detecta errores de firma
};
```

- Sin destructor virtual, borrar por puntero a base es comportamiento indefinido.
- `std::vector<std::unique_ptr<Shape>>` es la forma moderna de tener una
  coleccion heterogenea sin fugas.
- `make_unique` crea y transfiere la propiedad.

## Ejecutar

```powershell
cmake --build build --target mod06_demo mod06_tests
ctest --test-dir build -R mod06 --output-on-failure
```

## Ejercicios

En `ejercicios/README.md`:

1. Anade `Triangle` y `Square` como clases derivadas con tests.
2. Crea una clase `Contact` (nombre, email, edad) con validacion en el
   constructor y `operator==` por defecto.
3. Modela una `Agenda` que guarde contactos y exponga `add`, `find`, `remove`.
4. Anade `virtual std::string describe() const` a `Shape` e implementalo.
5. Explica por que no se debe usar `std::shared_ptr` por defecto.

## Criterios de entrega

- `ctest --test-dir build -R mod06` en verde.
- `Shape` no se puede instanciar directamente (es abstracta).
- Ningun `delete` manual: todo con `unique_ptr`.
- Tests de area con tolerancia, nunca `==` entre `double`.

Tag al hacer merge: `v0.06`.
