#include <stdio.h>

int main() {
  int qtd, i, j, temp;

  scanf("%d", &qtd);
  int array[qtd];

  for(i = 0; i < qtd; i++) {
    scanf("%d", &array[i]);
  }

  for(i = 0; i < qtd; i++) {
    for(j = i; j < qtd; j++) {
      if(array[i]> array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp; 
      }
    }
  }

  for(i = 0; i < qtd; i++) {
    printf("%d\n", array[i]);
  }

}