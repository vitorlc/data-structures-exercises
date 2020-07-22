#include <stdio.h>

int main() {

    int linha, coluna, qtdLinha, qtdColuna, count = 1;

    scanf("%d %d", &qtdLinha, &qtdColuna);
    
    int matriz[qtdLinha][qtdColuna];
    
    for(linha=0; linha < qtdLinha; linha++) {
        for(coluna=0; coluna < qtdColuna; coluna++) {
            if(linha%2 == 0) {
                if(coluna%2 == 1) {
                    matriz[linha][coluna] = count;
                    count ++;
                } else {
                    matriz[linha][coluna] = 0;
                }
            } else if (linha%2 == 1) {
                 if(coluna%2 == 0) {
                    matriz[linha][coluna] = count;
                    count ++;
                } else {
                    matriz[linha][coluna] = 0;
                }
            } 

        }
    }
    for(linha=0; linha < qtdLinha; linha++) {
        for(coluna=0; coluna < qtdColuna; coluna++) {
            printf("%d ", matriz[linha][coluna]);
        }
        printf("\n");
    }

    return 0;
}
