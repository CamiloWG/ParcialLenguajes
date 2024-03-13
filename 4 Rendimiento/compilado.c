#include <stdio.h>
#include <time.h>

unsigned long long factorial(unsigned long long n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n-1);
    }
}

int main() {
    unsigned long long n = 20;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    unsigned long long result = factorial(n);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("El factorial de %llu es %llu\n", n, result);
    printf("Tiempo de CPU utilizado: %f segundos\n", cpu_time_used);

    return 0;
}


