# 02 - Depurar con GDB

## Regla de oro

Compila siempre con informacion de depuracion y sin optimizar:

```powershell
cmake -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
```

o directamente:

```powershell
g++ -std=c++20 -g -O0 src/main.cpp -o app.exe
```

## En VS Code

1. `Ctrl+Shift+B` para compilar.
2. `F5` o Run and Debug -> "Debug modulo 00".
3. Puntos de ruptura con clic en el margen izquierdo.
4. Panel VARIABLES para inspeccionar valores; WATCH para expresiones.

`launch.json` ya apunta a `gdb.exe` de WinLibs y usa `-enable-pretty-printing`,
que muestra `std::vector`, `std::string` y `std::map` de forma legible.

## En terminal

```powershell
gdb .\build\00-hola-mundo\mod00_demo.exe
```

| Comando | Atajo | Que hace |
|---|---|---|
| `run` | `r` | inicia el programa |
| `break main` | `b main` | punto de ruptura en `main` |
| `break archivo.cpp:42` | `b ...` | punto de ruptura en linea |
| `next` | `n` | siguiente linea (sin entrar en funciones) |
| `step` | `s` | siguiente linea (entrando en funciones) |
| `finish` | | ejecutar hasta salir de la funcion actual |
| `continue` | `c` | continuar hasta el proximo breakpoint |
| `print x` | `p x` | mostrar valor de `x` |
| `print v` | `p v` | imprimir contenedor (pretty printing) |
| `watch x` | | parar cuando cambie `x` |
| `backtrace` | `bt` | pila de llamadas |
| `frame 2` | `f 2` | ir al marco 2 de la pila |
| `info locals` | | variables locales |
| `quit` | `q` | salir |

Ejemplo de sesion:

```
(gdb) b main
(gdb) run
(gdb) n
(gdb) p numbers
(gdb) watch numbers[0]
(gdb) c
```

## Segfault y excepciones

```powershell
# ver donde explota
gdb -batch -ex run -ex bt .\app.exe

# parar al lanzar una excepcion de C++
gdb .\app.exe
(gdb) catch throw
(gdb) run
(gdb) bt
```

## Sanitizers

Con GCC/Clang en Linux/WSL:

```bash
g++ -std=c++20 -g -fsanitize=address,undefined -fno-omit-frame-pointer src/main.cpp -o app
./app
```

Busca fugas, accesos fuera de rango y comportamiento indefinido. En MinGW el
soporte es parcial; para el modulo 11 usa WSL o clang si necesitas cobertura
completa.
