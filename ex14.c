#include <stdio.h>
#include <string.h>

#define DEZENAS 6

int main () {
    int qtd, i, j, k, winSena = 0, winQuina = 0, winQuadra = 0;
    scanf("%d", &qtd);
    int jogos[qtd][DEZENAS];
    int resposta[DEZENAS];

    for (i=0; i < qtd; i++){
        for(j=0; j< DEZENAS; j++){
            scanf("%d", &jogos[i][j]);
        }
    }

    for (i=0; i < DEZENAS; i++){
        scanf("%d", &resposta[i]);
    }



    for (i=0; i < qtd; i++){ // Varre a  linha
        int count = 0;
        for(j=0; j< DEZENAS; j++){ // Varre o número

            for (k = 0; k < DEZENAS; k++) { // Varre a resposta

                if(jogos[i][j] == resposta[k]){
                    count = count +1;
                    break;
                }
            }
        
        }
        if (count == 6) {
            winSena +=1;
        } else if (count == 5) {
            winQuina +=1;
        } else if (count == 4) {
            winQuadra +=1;
        }
    }

    if(winSena > 0){
        printf("Houve %d acertador(es) da sena\n", winSena);
    } else {
        printf("Nao houve acertador para sena\n");
    }

    if(winQuina > 0){
        printf("Houve %d acertador(es) da quina\n", winQuina);
    } else {
        printf("Nao houve acertador para quina\n");
    }
    
    if(winQuadra > 0){
        printf("Houve %d acertador(es) da quadra\n", winQuadra);
    }else {
        printf("Nao houve acertador para quadra\n");
    }
}