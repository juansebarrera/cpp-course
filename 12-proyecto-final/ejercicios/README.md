# Extensiones opcionales del proyecto final

Elige al menos dos para la v1.1.

## 01 - Busqueda parcial

```cpp
std::vector<Contact> Agenda::search(const std::string& fragment) const;
```

Case-insensitive, sobre nombre o email. Tests con mayusculas y acentos.

## 02 - Edicion

```cpp
bool Agenda::update(const std::string& name, Contact updated);
```

Mantiene el orden de insercion y rechaza cambiar el nombre a uno ya existente.

## 03 - Persistencia JSON

Sin librerias externas, define un formato minimo y escribelo a mano:

```json
[{"name": "Ana", "email": "ana@example.com", "age": 28}]
```

Documenta las limitaciones (escapes, comas en cadenas).

## 04 - Importar/exportar

Subcomandos en `main`:

```
agenda import contacts.csv
agenda export backup.csv
```

Separa la logica de CLI de la de negocio para poder testear sin `std::cin`.

## 05 - Empaquetado

Anade `install()` a CMake y genera un ZIP con CPack:

```cmake
include(InstallRequiredSystemLibraries)
set(CPACK_PACKAGE_NAME "agenda")
include(CPack)
```

```powershell
cpack --config build/CPackConfig.cmake
```
