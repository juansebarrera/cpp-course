# Ejercicios - Modulo 11 (Calidad)

## 01 - Mediana con casos limite

Prueba `median` con vector vacio, un elemento, dos elementos y valores repetidos.
Decide si `nth_element` deja el vector en un estado concreto y documentalo (no
debe importar al llamador porque recibe una copia).

## 02 - Test rojo a proposito

Escribe temporalmente:

```cpp
TEST_CASE(falla_a_proposito) {
    CHECK_EQ(1, 2);
}
```

Ejecuta `ctest --test-dir build -R mod11 --output-on-failure` y copia el reporte.
Elimina el test despues.

## 03 - Cobertura

Con GCC:

```powershell
cmake -B build-cov -G Ninja -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="--coverage"
cmake --build build-cov
ctest --test-dir build-cov
gcov -o build-cov\11-calidad build-cov\11-calidad\CMakeFiles\mod11_cal.dir\src\stats.cpp.gcda
```

Identifica lineas no cubiertas y anade tests.

## 04 - CI estricto

Crea `.github/workflows/strict.yml` que configure con:

```
-DCPP_COURSE_WERROR=ON
```

y falle si aparece cualquier warning. Corrige lo que salga.

## 05 - ASan

En WSL/Ubuntu, compila `tests/test_stats.cpp` con ASan y UBSan. Si todo esta
correcto no habra salida de error; prueba a anadir una lectura fuera de rango
temporal para ver el reporte y luego revertirlo.
