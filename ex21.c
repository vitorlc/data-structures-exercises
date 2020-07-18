#include <stdio.h>

int printNaturaisRecursivo(int num, int base);

int main () {
    int qtd;
    scanf("%d", &qtd);

    printNaturaisRecursivo(1, qtd);
    printf("\n");
    return 0;
}

int printNaturaisRecursivo(int num, int base) {
    if(num > base) {
        return 0;
    } else {
        printf("%d ", num);
        printNaturaisRecursivo(num + 1, base);
    }
}