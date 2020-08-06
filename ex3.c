#include <stdio.h>

int main() {
  int qtd, i, j, temp;

  scanf("%d", &qtd);
  float array[qtd];

  for(i = 1; i <= qtd; i++) {
    scanf("%f", &array[i]);
  }

  for(i = 1; i <= qtd; i++) {
    for(j = i; j <= qtd; j++) {
      if(array[i]> array[j]) {
        temp = array[i];
        array[i] = array[j];
        array[j] = temp; 
      }
    }
  }
  
  float result;
  if(qtd%2 == 1){
    result = array[(qtd/2)+1];
  } else {
    result = (array[(qtd/2)] + array[(qtd/2)+1])/2;
  }
  printf("%.2f\n", result);

}