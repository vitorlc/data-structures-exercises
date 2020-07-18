#include <stdio.h>

int fibonacciRecursivo(int n);

int main () {
    int qtd, i;
    scanf("%d", &qtd);

    for (i=-1; i<qtd; i++){
        printf("%d ", fibonacciRecursivo(i+1));
    }
    return 0;
}

int fibonacciRecursivo(int n) {
    if(n == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacciRecursivo(n-1)+fibonacciRecursivo(n-2);
    }
}