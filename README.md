# Curso de C++ desde cero

Repositorio de aprendizaje de C++ moderno (C++20) con ejercicios, tests y CI.
Cada modulo anade una capa al proyecto acumulativo: una **agenda de contactos**
que empieza como CLI sencilla y termina siendo una aplicacion robusta, testeada
y persistente.

[![CI](https://github.com/juansebarrera/cpp-course/actions/workflows/ci.yml/badge.svg)](https://github.com/juansebarrera/cpp-course/actions/workflows/ci.yml)

## Herramientas

| Herramienta | Version usada | Para que |
|---|---|---|
| MinGW-w64 (WinLibs, UCRT) | GCC 16.2.0 / GDB 18.1 | compilar y depurar |
| CMake | 4.4.4 | sistema de build |
| Ninja | 1.13.2 | generador de build |
| Git | cualquiera reciente | control de versiones |
| GitHub CLI (`gh`) | 2.103.3 | crear repo y PRs |
| VS Code + C/C++ + CMake Tools | ultimas | editor con IntelliSense y debug |

Detalle de instalacion y solucion de problemas: [docs/00-setup.md](docs/00-setup.md).

## Arranque rapido

```powershell
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

En Linux/macOS (g++ o clang++) los mismos comandos funcionan sin cambios.

## Estructura

```
CMakeLists.txt          build raiz (C++20, warnings, CTest)
tests/                  mini framework de tests usado por los modulos
docs/                   guias: setup, git, gdb, CMake, testing
00-hola-mundo/          modulo 00: toolchain y primer test
01-fundamentos/         ... 12-proyecto-final/
```

Cada modulo sigue el mismo patron:

```
XX-nombre/
  include/   cabeceras publicas del modulo
  src/       implementacion + demo ejecutable
  tests/     tests con CTest
  ejercicios/ enunciados y plantillas
  README.md  objetivos, ejercicios y criterios de entrega
```

## Temario

| # | Modulo | Entregable |
|---|---|---|
| 00 | [Hola mundo](00-hola-mundo/README.md) | toolchain + primer test en verde |
| 01 | [Fundamentos](01-fundamentos/README.md) | calculadora CLI |
| 02 | [Funciones](02-funciones/README.md) | conversor de unidades |
| 03 | [Modularidad](03-modularidad/README.md) | biblioteca propia + CMake |
| 04 | [STL secuencial](04-stl-secuencial/README.md) | agenda v1 |
| 05 | [Memoria y RAII](05-memoria/README.md) | agenda v2 |
| 06 | [POO](06-poo/README.md) | agenda v3 |
| 07 | [Genericos](07-genericos/README.md) | contenedor generico |
| 08 | [STL avanzada](08-stl-avanzada/README.md) | busqueda y filtros |
| 09 | [Errores](09-errores/README.md) | agenda robusta |
| 10 | [I/O y datos](10-io-datos/README.md) | persistencia CSV |
| 11 | [Calidad](11-calidad/README.md) | tests, gdb, sanitizers, CI |
| 12 | [Proyecto final](12-proyecto-final/README.md) | release v1.0.0 |

## Plan de 16 semanas

| Semana | Modulos | Foco |
|---|---|---|
| 1 | 00 | entorno, git, primer build y push |
| 2 | 01 | tipos, control de flujo, I/O |
| 3 | 01-02 | funciones, referencias, sobrecarga |
| 4 | 02-03 | headers, CMake, warnings |
| 5 | 03-04 | bibliotecas, `vector`, `string` |
| 6 | 04 | iteradores y `<algorithm>` |
| 7 | 05 | punteros, heap, RAII, smart pointers |
| 8 | 05-06 | repaso + inicio de POO |
| 9 | 06 | herencia y polimorfismo |
| 10 | 07 | templates y `constexpr` |
| 11 | 08 | `map`/`set`, lambdas, `std::function` |
| 12 | 09 | excepciones, `optional` |
| 13 | 10 | ficheros y CSV |
| 14 | 11 | CTest, Catch2, gdb, ASan/UBSan |
| 15 | 12 | diseno y desarrollo del proyecto |
| 16 | 12 | refactor, documentacion, release v1.0.0 |

## Flujo de trabajo

1. Rama por modulo: `git switch -c modulo-04`.
2. Commits pequenos con Conventional Commits (`feat(mod04): ...`).
3. Push y PR (aunque trabajes solo, el PR deja historial y CI).
4. Merge, tag `v0.04` y actualiza la checklist de progreso.

Detalle en [docs/01-flujo-git.md](docs/01-flujo-git.md).

## Progreso

- [x] Modulo 00 - Hola mundo
- [ ] Modulo 01 - Fundamentos
- [ ] Modulo 02 - Funciones
- [ ] Modulo 03 - Modularidad
- [ ] Modulo 04 - STL secuencial
- [ ] Modulo 05 - Memoria y RAII
- [ ] Modulo 06 - POO
- [ ] Modulo 07 - Genericos
- [ ] Modulo 08 - STL avanzada
- [ ] Modulo 09 - Errores
- [ ] Modulo 10 - I/O y datos
- [ ] Modulo 11 - Calidad
- [ ] Modulo 12 - Proyecto final

## Licencia

MIT, ver [LICENSE](LICENSE).
