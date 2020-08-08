#include <stdio.h>

void insertionSort(int vetor[], int tam);

int main () {
  int tam, i, l, k, soma;
  scanf("%d", &tam);
  int vetor[tam];
  for(i = 0; i < tam; i++){
    scanf("%d", &vetor[i]);
  }

  insertionSort(vetor, tam);
  scanf("%d %d", &l, &k);
  soma = vetor[l -1] + vetor[k -1];
  printf("%d\n", soma);
  
  return 0;
}

void insertionSort(int vetor[], int tam) {
   int i, j, aux;
    for (i = 1; i < tam; i++)
    {
        aux = vetor[i];
        j = i - 1;

        while ((j >= 0) && (aux < vetor[j]))
        {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = aux;
    }
}