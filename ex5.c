#include <stdio.h>

int main() {
  int qtd, i, j, resultado = 0;
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
    if(count == 1){
      resultado++;;
    }
  }

  printf("%d\n", resultado);
}