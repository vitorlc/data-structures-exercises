#include <stdio.h>

int main() {
  int nAlunos, qtdPresenca, i, count = 0;

  scanf("%d %d", &nAlunos, &qtdPresenca);
  int alunos[nAlunos];
  for(i = 0; i<nAlunos; i++){
    scanf("%d", &alunos[i]);
    if(alunos[i] <= 0) {

      count++;
    }
  }
  if(count >=  qtdPresenca) { // Tem Aula
    printf("NAO\n");
    for(i = nAlunos - 1; i >= 0; i--){
      if(alunos[i] <= 0) {
        printf("%d\n", i+1);
      }
    }
  } else { // Não tem
    printf("SIM\n");
  }

}
