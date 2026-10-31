# 01 - Flujo de trabajo con Git y GitHub

## Configuracion inicial (una sola vez)

Ya tienes identidad configurada:

```
user.name  = Juanse
user.email = juansebarrera@outlook.com
```

Si no la tuvieras:

```powershell
git config --global user.name "Tu Nombre"
git config --global user.email "tu@email.com"
git config --global init.defaultBranch main
```

## Crear el repositorio

```powershell
git init -b main
git add -A
git commit -m "chore: bootstrap C++ course repo"
gh auth login
gh repo create cpp-course --public --source=. --push
```

`gh auth login` es interactivo: elige GitHub.com -> HTTPS -> Login with a web
browser y pega el codigo de un solo uso que muestra la terminal.

## Ciclo por modulo

```powershell
git switch -c modulo-04
# ... trabajar ...
git add 04-stl-secuencial
git commit -m "feat(mod04): agenda v1 con vector y algorithms"
git push -u origin modulo-04
gh pr create --fill
```

Tras el merge:

```powershell
git switch main
git pull
git tag v0.04 -m "Modulo 04 completado"
git push --tags
```

## Conventional Commits

Formato: `tipo(alcance): descripcion`

| Tipo | Uso |
|---|---|
| `feat` | nueva funcionalidad o ejercicio |
| `fix` | corregir un bug |
| `test` | anadir o ajustar tests |
| `docs` | documentacion y apuntes |
| `refactor` | reorganizar sin cambiar comportamiento |
| `chore` | build, CI, tooling |

Ejemplos:

```
feat(mod01): calculadora CLI con menu
fix(mod05): evitar fuga en IntBuffer copiado
test(mod09): cubrir parse_int con entradas invalidas
docs(mod02): apuntes de paso por referencia
```

## Reglas del curso

1. Un commit por unidad logica, mensaje en presente.
2. Nunca subir `build/`, binarios ni `compile_commands.json`.
3. Todo PR debe pasar CI (build + ctest) antes del merge.
4. Actualiza la checklist del `README.md` en el PR del modulo.
5. Un tag por modulo: `v0.00` ... `v0.12`, y `v1.0.0` al final.

## Comandos utiles

```powershell
git status                     # estado del arbol de trabajo
git log --oneline --graph -15  # historial compacto
git diff                       # cambios sin stagear
git diff --staged              # cambios en stage
git restore <archivo>          # descartar cambios locales
git branch -a                  # ramas locales y remotas
gh pr status                   # estado de tus PRs
gh run list                    # ejecuciones de CI
```
