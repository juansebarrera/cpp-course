# Instala el toolchain del curso en Windows (winget) y verifica versiones.
$ErrorActionPreference = "Stop"

winget install -e --id BrechtSanders.WinLibs.POSIX.UCRT --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id Kitware.CMake --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id Ninja-build.Ninja --source winget --accept-package-agreements --accept-source-agreements
winget install -e --id GitHub.cli --source winget --accept-package-agreements --accept-source-agreements

code --install-extension ms-vscode.cpptools
code --install-extension ms-vscode.cmake-tools

Write-Host "Abre una terminal NUEVA y ejecuta: g++ --version; gdb --version; cmake --version; ninja --version; gh --version"
