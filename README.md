# Comparacion Factorial Recursivo vs Iterativo (Python y C)

## Proposito
Este proyecto tiene como objetivo comparar el rendimiento y el consumo de memoria entre dos metodos para calcular factoriales: recursivo e iterativo.  
Se implementaron ambas versiones en Python y en C para evaluar las diferencias en velocidad, uso de memoria y limitaciones propias de cada lenguaje.

---

## Implementacion de las funciones
- **Recursivo:** La funcion se llama a si misma hasta llegar al caso base (n <= 1). Cada llamada genera un nuevo marco en la pila de ejecucion.
- **Iterativo:** Utiliza un bucle `for` para multiplicar los numeros desde 1 hasta n, evitando llamadas anidadas y reduciendo el uso de la pila.

---

## Metodos para medir tiempo y memoria
- **Python:**
  - Tiempo: `time.time()`
  - Memoria: `memory_profiler`
- **C:**
  - Tiempo: `clock()` de `time.h`
  - Memoria: `getrusage()` de `sys/resource.h`
  - Visualizacion de datos: `gnuplot`

---

## Hallazgos y comparaciones
### Python
- **Recursivo:**
  - Limite de calculo: hasta 247! (a partir de 248 ocurre `RecursionError` por limite de profundidad).
  - Tiempo para 247!: ~23.74 s
  - Memoria: ~26.9 MiB
- **Iterativo:**
  - Sin limite de recursividad (solo limitado por memoria disponible).
  - Tiempo para 248!: ~0.03 s
  - Memoria: ~25.7 MiB

### C
- **Recursivo e Iterativo:**
  - No presentan el limite de recursividad tan bajo como Python, pero estan limitados por el rango del tipo de dato (`unsigned long long`) y la memoria disponible.
  - Ejecucion mucho mas rapida que Python para valores grandes.
  - Memoria estable y baja en ambos metodos.

### Comparacion general
- El metodo iterativo es mas rapido y ligeramente mas eficiente en memoria.
- El metodo recursivo es mas elegante, pero menos practico para valores grandes debido a la profundidad de la pila.

---

## Paso a paso para ejecutar

### Python
1. Instalar Python 3
2. Instalar dependencias:
   pip install memory_profiler matplotlib

   ## Dependencias en C

Necesitas:
- **gcc** (o clang) para compilar
- **gnuplot** para mostrar la grafica

### Linux (Ubuntu/Debian/WSL)
sudo apt update
sudo apt install build-essential gnuplot

## Hecho por Johan Steven Galeano Gonzalez G02

