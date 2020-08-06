#include <stdio.h>

#define ORDEM 6

int main(){
    // Cárceres 0
    // Bugres 1
    // Cuiabá 2
    // Várzea 3
    // Tangará 4
    // Lacerda 5
    int matriz[ORDEM][ORDEM] = {0, 63, 210, 190, -1, 190, 63, 0, 160, 150, 95, 10, 210, 160, 0, 10, 1, 10, 190, 150, 10, 0, 10, 20, 10, 95, 7, 21, 0, 80, 190, 2, -1, 41, 80, 0};
    int i, j;

    // for (i = 0; i < ORDEM; i++){
    //     for (j = 0; j < ORDEM; j++){
    //         printf("%d ", matriz[i][j]);
    //     }
    //     printf("\n");
    // }
    int n;
    scanf("%d", &n);
    int trajeto[n];
    
    for (i = 0; i < n; i++){
        scanf("%d", &trajeto[i]);
    }
    int soma=0;
    for (i = 0; i < n-1; i++){
        if (matriz[trajeto[i]][trajeto[i+1]] == -1) {
            soma = -1;
            break;
        }
        soma += matriz[trajeto[i]][trajeto[i+1]];
    }
    if(soma > 0) {
        printf("%d\n", soma);
    } else {
        printf("rota invalida!\n");
    }

    return 0;
}