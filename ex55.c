#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct neto Neto;
struct neto {
  char nome[15];
  Neto *proxNeto;
};

Neto* lista = NULL;
Neto* insereNeto(Neto* lista, char nome[]);
void imprimeLista(Neto* lista);

int main () {
  int qtdNetos = 0, i;
  char nome[15], sentido[10];

  do { 
    scanf("%s", nome);
    lista = insereNeto(lista, nome);

  } while (strcmp(nome,"FIM") != 0); 

  Neto* temp = lista;
  Neto circulo[7];
  int j = 0;
  while(temp->proxNeto){
    circulo[j] = *temp;
    qtdNetos++;
  }

  for (i = 0; i < qtdNetos; i++) {
    printf("%s", circulo[i].nome);
  //  scanf("s", nome, sentido);

  //   if(strcmp(sentido,"horario") == 0){

  //   } else if (strcmp(sentido,"anti-horario") == 0) {
      
  //   }
  }


  // imprimeLista(lista);
}


Neto* insereNeto(Neto* lista, char nome[]){
  Neto* novoNeto = (Neto *) malloc(sizeof(Neto));
  strcpy(novoNeto->nome, nome);
  novoNeto->proxNeto= NULL;

  if(lista == NULL) {
    lista = novoNeto;
  } else {
    Neto* temp = lista;
    while(temp->proxNeto){
      temp=temp->proxNeto;
    }
    temp->proxNeto = novoNeto;
  }
  return lista;
}

void imprimeLista(Neto* lista) {
  Neto* temp = lista;
  while (temp->proxNeto) {
    printf("%s\n", temp->nome);
    temp= temp->proxNeto;
  }
}