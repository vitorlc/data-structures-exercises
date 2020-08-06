#include <stdio.h>

typedef struct num{
  int num;
  int qtd;
} Num;


int main() {
  int qtd, i, j, temp;

  Num maiorValor;
  maiorValor.qtd = 0;

  scanf("%d", &qtd);
  int array[qtd];

  for(i = 0; i < qtd; i++) {
    scanf("%d", &array[i]);
  }

  for(i = 0; i < qtd; i++) {
    int count = 0;
    for(j = 0; j < qtd; j++) {
      if(array[j] == array[i]) {
        count++;
      }
    }
    if (count > maiorValor.qtd) {
      maiorValor.num = array[i];
      maiorValor.qtd = count;
    }
  }
  printf("%d\n", maiorValor.num);
  printf("%d\n", maiorValor.qtd);
}