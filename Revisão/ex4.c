#include <stdio.h>

int reverse(int numero);

int main() {
    int n = 0;
    scanf("%d", &n);
    int entradas[n], i = 0;
    for (i=0; i<n; i++) {
        scanf("%d", &entradas[i]);
        
    }
    for (i=0; i<n; i++) {
        if(reverse(entradas[i]) == entradas[i]){
            printf("yes ");
        }else {
            printf("no ");
        }
        
    }
    printf("\n");
    return 0; 
}


int reverse(int numero) {
    int reverse = 0;
    while(numero!= 0) {
        reverse = reverse * 10;
        reverse = reverse + numero%10;
        numero = numero/10;
    }
    return reverse;
}