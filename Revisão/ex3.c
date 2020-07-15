#include <stdio.h>
#include <string.h>

void main () {
    int n=0, n1=0, n2=0, resultado = 0;
    char c[]=" ";


    scanf("%d", &n);
    scanf("%d %c %d", &n1, &c[0], &n2);
    
    if(strcmp(c, "x")) {
        resultado = n1 * n2;
    } else if (strcmp(c, "+")) {
        resultado = n1 + n2;
    }

    if(resultado > n) {
        printf("overflow\n");
    } else if (resultado < n) {
        printf("no overflow\n");
    }
}