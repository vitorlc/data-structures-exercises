#include <stdio.h>

#define ORDEM 6

int calculaAmpulheta(int linha, int coluna, int matriz[ORDEM][ORDEM]) {
    int soma, a, b, c, d, e, f, g;
    if ((linha + 2 >= ORDEM) || (coluna+2 >= ORDEM)) {
        return 0;
    }
    a = matriz[linha][coluna];
    b = matriz[linha][coluna+1];
    c = matriz[linha][coluna+2];
    d = matriz[linha+1][coluna+1];
    e = matriz[linha+2][coluna];
    f = matriz[linha+2][coluna+1];
    g = matriz[linha+2][coluna+2];
    soma = a + b + c + d + e + f + g; 
    return soma;
   
}

int main() {

    int linha, coluna, matriz[ORDEM][ORDEM], maior=0;

    for(linha=0; linha < ORDEM; linha++) {
        for(coluna=0; coluna < ORDEM; coluna++) {
            scanf("%d", &matriz[linha][coluna]);
        }
    }
    for(linha=0; linha < ORDEM; linha++) {
        for(coluna=0; coluna < ORDEM; coluna++) {
            if (maior < calculaAmpulheta(linha, coluna, matriz)) {
                maior = calculaAmpulheta(linha, coluna, matriz);
            }
        }
    }

    printf("%d\n", maior);
    return 0;
}
