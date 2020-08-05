#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato Contato;
struct contato{
    char nome[15];
    char telefone[20];
    int qtd_ligacao;
    Contato *proxContato;
};

Contato* lista = NULL; //lista vazia
Contato* criaContato();
Contato* insereContato(Contato *Lista, char nome[], char telefone[], int qtd_ligacao);
Contato* buscarContato(Contato* Lista, char nome[]);
Contato* removerContato(Contato *Lista, char nome[]);
void registraLigacao(Contato *Lista, char nome[]);
void imprimir(Contato *Lista);

int main (){
    char tipo, nome[15]; 
    char telefone[20]; 
    int qtd_ligacao = 0;

    strcpy(nome, "Hermanoteu");
    strcpy(telefone, "4523-2248");
    lista = insereContato(lista, nome, telefone, 300);
    strcpy(nome, "Ooloneia");
    strcpy(telefone, "4523-4887");
    lista = insereContato(lista, nome, telefone, 299);

    do{
        scanf("%c", &tipo);
        switch(tipo)
        {
            case 'I':
            scanf("%s %s %d", nome, telefone, &qtd_ligacao);
            lista = insereContato(lista ,nome, telefone, qtd_ligacao);
            break;

            case 'R':
            scanf("%s", nome);
            lista = removerContato(lista, nome);
            break;

            case 'L':
            scanf("%s", nome);
            registraLigacao(lista, nome);
            break;

        }
    }while(tipo!='F');
    
    imprimir(lista);

    return 0;
};

Contato* criaContato(){
    Contato *contato = (Contato*)malloc(sizeof(Contato));
    return contato;
}

Contato* insereContato(Contato *Lista, char nome[], char telefone[], int qtd_ligacao){
    Contato *contato = criaContato(); 

    strcpy(contato->nome,nome);
    strcpy(contato->telefone, telefone);
    contato->qtd_ligacao = qtd_ligacao;
    contato->proxContato = NULL;

    if(Lista == NULL){
        Lista = contato;
    }else{ 
        Contato *temp = Lista;          
        while(temp->proxContato != NULL){
            temp = temp->proxContato;
        }
        temp->proxContato = contato;
    }

    return Lista;
}

Contato* buscarContato(Contato* Lista, char nome[]){
    Contato* temp = Lista;
    while (strcmp(temp->nome, nome) != 0){
        temp = temp->proxContato;
    }
    
    return temp;
}

Contato* removerContato(Contato *Lista, char nome[]){

    Contato *temp = buscarContato(lista, nome);

    Contato *anteriorTemp;
    anteriorTemp = lista;
    if(anteriorTemp == temp) {
        Lista = anteriorTemp->proxContato;
        free(temp);
        return Lista;
    }else {
        while( anteriorTemp->proxContato != temp ){
            anteriorTemp = anteriorTemp->proxContato;
        }
        anteriorTemp->proxContato = temp->proxContato;
        free(temp);
        return Lista;
    }
}

void registraLigacao(Contato *Lista, char nome[]){
    Contato *temp = buscarContato(lista, nome);
    temp->qtd_ligacao = temp->qtd_ligacao +1;
}

void imprimir(Contato *Lista){
    Contato* aux = Lista;
    while(aux !=NULL){
        printf("%s - %s %d\n", aux->nome, aux->telefone, aux->qtd_ligacao);
        aux=aux->proxContato;
    }
    printf("\n");
}

