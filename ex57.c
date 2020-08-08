#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lista{
    char nome[1000];
    int num;
    struct lista* dir;
    struct lista* esq;
}Lista;

Lista* iniciaLista(){
    Lista*T = NULL;

    return T;
}


void insereLista(Lista** T, char* nome, int n){
    Lista* p = malloc(sizeof(Lista));

    strcpy(p->nome, nome);
    p->num=n;
    p->dir=NULL;
    p->esq=NULL;

    if((*T)==NULL){
        (*T)=p;
        (*T)->dir=(*T);
        (*T)->esq=(*T);
        return;
    }

    Lista* q=(*T);

    while(q->esq!=(*T))q=q->esq;

    q->esq=p;
    p->esq=(*T);
    p->dir=q;
    (*T)->dir=p;
}


void removeLista(Lista** T, char* nome){
    Lista* q=(*T);
    Lista* p=(*T);

    while(strcmp(nome, q->nome)!=0){
        p=q;
        q=q->dir;
    }

    if(q==(*T)){
        p=(*T)->esq;
        p->dir=q->dir;

        p=q->dir;
        p->esq=q->esq;

        (*T)=q->esq;

        free(q);

        return;
    }

    Lista* k;

    p->dir=q->dir;
    k=q->dir;
    k->esq=p;

    free(q);
    return;

}


int main(){
    int n;

    Lista* T = iniciaLista();

    scanf("%d", &n);

    int i;

    for(i=0; i<n; i++){
        getchar();
        char nome[100];
        int num;

        scanf("%s", nome);
        scanf("%d", &num);

        insereLista(&T, nome, num);
    }

    n--;

    Lista*p =T;


    int k=p->num;
    while(n--){
        if(k%2==0){
            int c=p->num;
            for(i=0, p=T; i<c; i++){
                p=p->dir;
            }
        }
        
        if(k%2!=0){
            int c=p->num;
            for(i=0, p=T; i<c; i++){
                p=p->esq;
            }
        }
        k=p->num;
        removeLista(&T, p->nome);
    }

    printf("%s\n", T->nome);
    
}