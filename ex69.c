#include <stdio.h>
#include <stdlib.h>
#define limit 10000

void enumeracao();

int mdc(int n, int d);

int main(){

    enumeracao();

    return 0;
}

void enumeracao(){

    int k,n,d,c=0;
    int resultados[10000][2];
    int entradas=0, i;

    do
    {
        scanf("%i", &k);

        if (k == 0) {
          continue;
        }

        for (d=1; d<=limit; d++){
            for(n=0; n<=d; n++){
                if(mdc(n,d) == 1){
                    c++;
                    if (c==k){
                        resultados[entradas][0] = n;
                        resultados[entradas][1] = d;
                        n = limit;
                    }
                }
            }

            if (c==k)
            {
                d = limit;
            }
        }

        c=0;
        entradas++;

    }
    while(k!=0);

    for (i = 0; i < entradas; i++) {
      printf("%i/%i\n",resultados[i][0],resultados[i][1]);
    }
}

int mdc(int a, int b){
    int resto;

    while (b!=0){
        resto = a%b;
        a = b;
        b = resto;
    }

    return a;
}
