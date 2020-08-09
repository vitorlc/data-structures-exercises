#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;

struct fila {
    int indentificador;
    Fila *prox;
};

Fila *addFila(int identificadorPessoa, Fila *fila);
void printFila(Fila *fila);
Fila *removeFila (int identificadorPessoa, Fila *fila);

int main() {
    Fila *fila = NULL;
    int qtdPessoas = 0, qtdSairam = 0, i;

    scanf("%d", &qtdPessoas);

    for (i = 0; i<qtdPessoas; i++){
        int identificadorPessoa = 0;
        scanf("%d", &identificadorPessoa);
        fila = addFila(identificadorPessoa, fila);
    
    }

    scanf("%d", &qtdSairam);
    int identificadores[qtdSairam];
    for (i = 0; i<qtdSairam; i++){
        scanf("%d", &identificadores[i]);
    }
    for (i = 0; i<qtdSairam; i++){
        fila = removeFila(identificadores[i], fila);
    }

    printFila(fila);
    printf("\n");
    return 0;
}

Fila *criaPessoa() {
    Fila *p = (Fila *)malloc(sizeof (Fila));
    return p; 
}

Fila *addFila(int identificadorPessoa, Fila *fila){
    Fila *pessoa = criaPessoa();
    pessoa->indentificador = identificadorPessoa;
    pessoa->prox == NULL;
    
    if (fila == NULL){
        fila = pessoa;
    } else {
        Fila *temp = fila;
        while (temp->prox) {

            temp=temp->prox;
        }
        temp->prox = pessoa;
    }
    return fila;
}

void printFila(Fila *fila) {
    Fila *temp = fila;
    while (temp != NULL){
        printf("%d ", temp->indentificador);
        temp = temp->prox;
    };
}

Fila *removeFila (int identificadorPessoa, Fila *fila) {
    Fila *temp = fila;
    while (temp->indentificador != identificadorPessoa){
        temp = temp->prox;
    }
    Fila *anterior = fila;
    
    if(anterior == temp) {
        fila = anterior->prox;
        free(temp);
        return fila;
    } else {
        while (anterior->prox != temp) {
            anterior = anterior->prox;
        }
        anterior->prox = temp->prox;
        free(temp);
        return fila;
    }
    
}