#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/resource.h>
#include <math.h>


unsigned long long factorial_recursivo(int n) {
    if (n <= 1) return 1;
    return n * factorial_recursivo(n - 1);
}


unsigned long long factorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}


double get_memory_usage() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss / 1024.0; 
}

int main() {
    int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);

    
    clock_t start_r = clock();
    unsigned long long resultado_r = factorial_recursivo(numero);
    clock_t end_r = clock();
    double tiempo_r = (double)(end_r - start_r) / CLOCKS_PER_SEC;
    double memoria_r = get_memory_usage();

    
    clock_t start_i = clock();
    unsigned long long resultado_i = factorial_iterativo(numero);
    clock_t end_i = clock();
    double tiempo_i = (double)(end_i - start_i) / CLOCKS_PER_SEC;
    double memoria_i = get_memory_usage();

    
    printf("\nFactorial recursivo (%d) = %llu\n", numero, resultado_r);
    printf("Tiempo: %.6f s, Memoria: %.2f MiB\n", tiempo_r, memoria_r);
    printf("Factorial iterativo (%d) = %llu\n", numero, resultado_i);
    printf("Tiempo: %.6f s, Memoria: %.2f MiB\n", tiempo_i, memoria_i);

    
    FILE *fp = fopen("datos.txt", "w");
    fprintf(fp, "Metodo\tTiempo\tMemoria\n");
    fprintf(fp, "Recursivo\t%.6f\t%.2f\n", tiempo_r, memoria_r);
    fprintf(fp, "Iterativo\t%.6f\t%.2f\n", tiempo_i, memoria_i);
    fclose(fp);

    
    FILE *gp = popen("gnuplot -persistent", "w");
    fprintf(gp, "set title 'Comparacion Factorial Recursivo vs Iterativo'\n");
    fprintf(gp, "set style data histograms\n");
    fprintf(gp, "set style fill solid 1.0 border -1\n");
    fprintf(gp, "set key outside\n");
    fprintf(gp, "set boxwidth 0.5\n");
    fprintf(gp, "set ylabel 'Tiempo (s) y Memoria (MiB)'\n");
    fprintf(gp, "plot 'datos.txt' using 2:xtic(1) title 'Tiempo (s)', '' using 3 title 'Memoria (MiB)'\n");
    pclose(gp);

    return 0;
}
