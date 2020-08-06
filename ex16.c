#include <stdio.h>

#define LEN(arr) ((int) (sizeof (arr) / sizeof (arr)[0]))

int main () {
    int linha, coluna, i, j, k=0;
    scanf("%d %d", &linha, &coluna);
    int matriz[linha][coluna];
    int qtd = linha*coluna;
    int resp[qtd];

    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
    for(i=0; i<linha; i++){
        for(j=0; j<coluna; j++) {
            resp[k]= matriz[i][j];
            k++;
        }
    }

    typedef struct numQtd {
        int numero;
        int qtd;
    } NumQtd;

    NumQtd maior;
    NumQtd menor;
    maior.qtd = 0;
    menor.qtd = qtd;
   
    for(i=0; i<qtd; i++){
        int count = 0;
        for(j=0; j<qtd; j++){
            if(resp[i] == resp[j]){
                count++;
            }
        }

        // if(count==maior.qtd) {
        //     maior.qtd = count;
        //     maior.numero = resp[i];
        // }
        // if(count==menor.qtd) {
        //     menor.qtd = count;
        //     menor.numero = resp[i];
        // }

        if(count>maior.qtd || ((count == maior.qtd) && (resp[i] > maior.numero))) {
            maior.qtd = count;
            maior.numero = resp[i];
        }
        if(count<menor.qtd || ((count == menor.qtd) && (resp[i] > menor.numero))) {
            menor.qtd = count;
            menor.numero = resp[i];
        }
    }

    printf("%d %.2f%%\n", maior.numero, (maior.qtd*100.0)/qtd);
    printf("%d %.2f%%\n", menor.numero, (menor.qtd*100.0)/qtd);



    return 0;
}
