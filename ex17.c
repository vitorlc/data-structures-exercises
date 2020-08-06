#include <stdio.h>

int main () {
  int n, i, j, aux, temp;
  scanf("%d", &n);
  
  int matriz[n][n];

  for(i = 0; i < n; i++){
    for(j = 0; j< n; j++){
      scanf("%d", &matriz[i][j]);
    }
  }

  for(j = n-1; j >=0 ; j--){
    for(i = n-1; i >=0 ; i--){
      for (temp = i-1; temp >= 0; temp--) {
        if(matriz[i][j] < matriz[temp][j]) {
          aux = matriz[i][j];
          matriz[i][j] = matriz[temp][j];
          matriz[temp][j] = aux; 
        }

      }
    }
  }


  for(i = 0; i < n; i++){
    for(j = 0; j < n; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

}