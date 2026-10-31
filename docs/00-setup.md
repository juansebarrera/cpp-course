# 00 - Entorno de trabajo

Todo lo que necesitas para compilar, depurar y testear los modulos del curso.

## Versiones instaladas

| Herramienta | Version verificada |
|---|---|
| MinGW-w64 (WinLibs, UCRT, POSIX/SEH) | GCC 16.2.0 |
| GDB | 18.1 |
| CMake | 4.4.4 |
| CTest | 4.4.4 |
| Ninja | 1.13.2 |
| GitHub CLI | 2.103.3 |
| VS Code | ultima |

Ruta del compilador en este equipo:

```
C:\Users\juans\AppData\Local\Microsoft\WinGet\Packages\BrechtSanders.WinLibs.POSIX.UCRT_Microsoft.Winget.Source_8wekyb3d8bbwe\mingw64\bin
```

## Instalacion (repetible)

Usa el script [setup.ps1](../setup.ps1) o ejecuta:

```powershell
winget install -e --id BrechtSanders.WinLibs.POSIX.UCRT --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id Kitware.CMake --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id Ninja-build.Ninja --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id GitHub.cli --source winget --accept-package-agreements --accept-source-agreements
code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools
```

`--source winget` evita el origen `msstore`, que pide aceptar un contrato y falla
en modo no interactivo (`0x8a150042`).

## Verificacion

Abre una terminal **nueva** (el PATH solo se refresca al abrir procesos nuevos):

```powershell
g++ --version      # g++ (MinGW-W64 x86_64-ucrt-posix-seh) 16.2.0
gdb --version      # GNU gdb 18.1
cmake --version    # cmake version 4.4.4
ctest --version    # ctest version 4.4.4
ninja --version    # 1.13.2
gh --version       # gh version 2.103.3
```

## Compilar a mano (sin CMake)

```powershell
g++ -std=c++20 -Wall -Wextra -Wpedantic 00-hola-mundo/src/main.cpp 00-hola-mundo/src/hello.cpp -I 00-hola-mundo/include -o hello.exe
.\hello.exe
```

`-I` indica donde estan las cabeceras (`hello/hello.hpp`).

## Compilar con CMake (forma del curso)

```powershell
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
ctest --test-dir build --output-on-failure
```

- `build/` esta en `.gitignore`: nunca se sube al repo.
- Si Ninja no aparece, usa `-G "MinGW Makefiles"` o reinstala Ninja.
- Para regenerar desde cero: borra la carpeta `build/`.

## VS Code

- `Ctrl+Shift+B` ejecuta la tarea por defecto: **CMake: build**.
- `Ctrl+Shift+P` -> `Tasks: Run Test Task` ejecuta **CTest: run**.
- `F5` lanza el debugger con la configuracion "Debug modulo 00".
- Si IntelliSense no resuelve cabeceras, ejecuta el configure y comprueba
  `build/compile_commands.json`.

## Problemas comunes

| Sintoma | Causa / solucion |
|---|---|
| `g++` no se reconoce | terminal abierta antes de instalar; abrir una nueva |
| CMake no encuentra compilador | `cmake --version` ok pero sin `g++` en PATH; revisar PATH de usuario |
| `build/` con bloqueos o lento | OneDrive sincronizando `build/`; mueve el build a `%TEMP%` con `-B "$env:TEMP\cpp-build"` |
| Warning de `msstore` | anadir `--source winget` a los comandos de `winget` |
| `import std;` falla | MinGW no trae el modulo estandar de C++23; el curso usa C++20 |

## Sanitizers (modulo 11)

Comprobado en este equipo: **WinLibs no incluye `libasan`**, asi que
`-fsanitize=address` falla al enlazar (`cannot find -lasan`). Si necesitas
ASan/UBSan completos, usa WSL + Ubuntu (`sudo apt install build-essential gdb
cmake ninja-build`) o clang en Linux. En Windows, MSVC tambien soporta ASan.
