from memory_profiler import memory_usage
import time
import matplotlib.pyplot as plt


def factorial_recursivo(n):
    if n == 0 or n == 1:
        return 1
    else:
        return n * factorial_recursivo(n - 1)


def factorial_iterativo(n):
    resultado = 1
    for i in range(2, n + 1):
        resultado *= i
    return resultado


def medir_rendimiento(func, n):
    inicio_tiempo = time.time()
    mem_usage, resultado = memory_usage((func, (n,)), retval=True, max_iterations=1)
    fin_tiempo = time.time()
    tiempo_total = fin_tiempo - inicio_tiempo
    memoria_max = max(mem_usage)  
    return tiempo_total, memoria_max, resultado

if __name__ == "__main__":
    numero = int(input("Ingrese un numero: "))

    
    tiempo_rec, mem_rec, res_rec = medir_rendimiento(factorial_recursivo, numero)

    
    tiempo_iter, mem_iter, res_iter = medir_rendimiento(factorial_iterativo, numero)

    
    print(f"\nResultados para n = {numero}:")
    print(f"Recursivo - Resultado: {res_rec}\nTiempo: {tiempo_rec:.6f} s, Memoria: {mem_rec:.6f} MiB")
    print(f"Iterativo - Resultado: {res_iter}\nTiempo: {tiempo_iter:.6f} s, Memoria: {mem_iter:.6f} MiB")

    
    metodos = ["Recursivo", "Iterativo"]
    tiempos = [tiempo_rec, tiempo_iter]
    memorias = [mem_rec, mem_iter]

    x = range(len(metodos))
    fig, ax1 = plt.subplots()

    
    ax1.bar(x, tiempos, width=0.4, label="Tiempo (s)", align='center')
    ax1.set_ylabel("Tiempo (segundos)")
    ax1.set_xlabel("Metodos")

    
    ax2 = ax1.twinx()
    ax2.bar([i + 0.4 for i in x], memorias, width=0.4, color='orange', label="Memoria (MiB)")
    ax2.set_ylabel("Memoria (MiB)")

    
    plt.title(f"Comparacion rendimiento factorial para n={numero}")
    ax1.legend(loc="upper left")
    ax2.legend(loc="upper right")

    plt.xticks([i + 0.2 for i in x], metodos)
    plt.show()
