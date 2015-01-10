#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE    1000

long long int f[MAX_SIZE];

long long int fib(int n, int xth) {
    f[0] = 0;
    f[1] = 1;
    long long int sum;
    
    if (xth == 0)
        return f[0];
    if (xth == 1)
        return f[1];
    
    for (int i = 2; i <= xth; i++) {
        sum = 0;
        for (int j = 1; j <= n && j < i; j++) 
            sum += f[i - j];
        f[i] = sum;
    }

    return f[xth];
}

int main(int argc, char *argv[]) {
    clock_t start, end;
    start = clock();

    if (argc != 3) {
        printf("Usage: nfib 3 14 = Calculate the 14th Fibonacci number by adding the previous 3 numbers instead of 2.\n");
        return 0;
    }

    long long int x = fib(strtol(argv[1], NULL, 10), strtol(argv[2], NULL, 10));
    printf("x = %lld\n", x);

    end = clock();
    double executionTime = (double) (end - start) / CLOCKS_PER_SEC;
    printf("Program ran in %f seconds\n", executionTime);
}
