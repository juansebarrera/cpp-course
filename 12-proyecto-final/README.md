# Modulo 12 - Proyecto final: Agenda

Punto de partida del proyecto acumulativo. La base ya funciona: agregar, buscar,
eliminar y listar contactos en memoria. Tu trabajo es llevarla a una aplicacion
completa y publicar `v1.0.0`.

## Estado actual

| Pieza | Estado |
|---|---|
| `agenda::Contact` con `operator==` | hecho |
| `Agenda::add` (rechaza duplicados) | hecho |
| `Agenda::find` / `remove` / `contacts` | hecho |
| CLI con menu | hecho (basico) |
| Persistencia CSV | pendiente |
| Validacion de email y edad | pendiente |
| Tests de integracion | pendiente |
| Documentacion y release | pendiente |

## Requisitos de la v1.0.0

1. Persistencia en `agenda.csv` (cargar al inicio, guardar al salir) reutilizando
   el modulo 10.
2. Validacion: nombre no vacio, email con `@`, edad entre 0 y 120; errores
   claros al usuario.
3. Busqueda por nombre parcial (case-insensitive) ademas de exacta.
4. Edicion de un contacto existente.
5. Tests que cubran cada funcionalidad y los casos limite.
6. `README.md` del proyecto con uso, formato del CSV y limitaciones.
7. Release `v1.0.0` con changelog y tag en GitHub.
8. CI en verde en Windows y Linux.

## Hitos sugeridos (semanas 15-16)

| Hito | Contenido | Commit |
|---|---|---|
| 1 | Validacion + errores | `feat(mod12): validacion de contactos` |
| 2 | Persistencia CSV | `feat(mod12): persistencia en agenda.csv` |
| 3 | Busqueda parcial y edicion | `feat(mod12): busqueda parcial y edicion` |
| 4 | Tests de integracion | `test(mod12): cobertura completa` |
| 5 | Documentacion + release | `docs(mod12): release v1.0.0` |

## Ejecutar

```powershell
cmake --build build --target mod12_agenda_cli mod12_tests
ctest --test-dir build -R mod12 --output-on-failure
.\build\12-proyecto-final\mod12_agenda_cli.exe
```

## Estructura recomendada al terminar

```
12-proyecto-final/
  include/agenda/agenda.hpp      # API publica
  src/agenda.cpp                 # logica
  src/storage.cpp                # persistencia (nuevo)
  src/main.cpp                   # CLI
  tests/test_agenda.cpp
  tests/test_storage.cpp         # nuevo
  README.md
  CHANGELOG.md                   # nuevo
```

## Entrega final

```powershell
git switch -c proyecto-final
# ... desarrollo ...
git tag v1.0.0 -m "Primera version completa de la agenda"
git push origin proyecto-final --tags
gh release create v1.0.0 --generate-notes
```
