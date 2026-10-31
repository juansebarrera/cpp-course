# Ejercicios - Modulo 06 (POO)

## 01 - Mas figuras

Anade a `poo`:

```cpp
class Triangle final : public Shape { /* base, height */ };
class Square final : public Shape { /* side */ };
```

Anade `make_unique` en la demo y tests de area y nombre.

## 02 - Contacto

```cpp
class Contact {
public:
    Contact(std::string name, std::string email, int age);
    const std::string& name() const;
    const std::string& email() const;
    int age() const;
    bool operator==(const Contact& other) const = default;

private:
    std::string name_;
    std::string email_;
    int age_ = 0;
};
```

Reglas de validacion: nombre no vacio, email contiene `@`, edad entre 0 y 120.
Lanza `std::invalid_argument` si falla.

## 03 - Agenda v2

```cpp
class Agenda {
public:
    void add(Contact contact);
    std::optional<Contact> find(const std::string& name) const;
    bool remove(const std::string& name);
    std::size_t size() const;
};
```

Implementa con un `std::vector<Contact>` privado.

## 04 - describe()

Anade a `Shape`:

```cpp
virtual std::string describe() const = 0;
```

Implementalo en cada figura combinando nombre y area (por ejemplo
`"circulo de area 12.57"`).

## 05 - unique vs shared

Escribe un parrafo en el README explicando:

- por que `unique_ptr` es la opcion por defecto,
- que coste tiene `shared_ptr` (conteo atomico, ciclo potencial),
- como romper un ciclo con `std::weak_ptr`.
