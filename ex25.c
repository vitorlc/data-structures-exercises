#include<stdio.h>

void binarioRecursivo(int n);


int main() {

    int qtd, i;

    scanf("%d", &qtd);

    int n[qtd];

    for (i = 0; i<qtd; i++) {
        scanf("%d", &n[i]);
    }

    for (i = 0; i<qtd; i++) {
        binarioRecursivo(n[i]);
        printf("\n");
    }

    return 0;
}


void binarioRecursivo(int n) {
    if (n/2 != 0) {
        binarioRecursivo(n/2);
    } 
    printf("%d", n%2);  
}