#include <stdio.h>
#include <stdlib.h>

typedef struct paciente Paciente;

struct paciente{
   int chegada;
   int tempoCritico;
   Paciente *proximo;
};

Paciente *addPacienteFila(int chegada, Paciente *lista, int tempoCritico);
Paciente *criaPaciente();
void  imprimeFila(Paciente* lista);
int verficaPacienteCritico(Paciente *lista);

int main() {
    int qtdPacientes, i, horas, minutos, tempoCritico, chegada, qtdCritico = 0;

    Paciente *lista = NULL;
    
    scanf("%d", &qtdPacientes);

    for (i = 0; i<qtdPacientes; i++){
        scanf("%d %d %d", &horas, &minutos, &tempoCritico);
        chegada = minutos + horas * 60;

        lista = addPacienteFila(chegada, lista, tempoCritico);
    }
    // imprimeFila(lista);

    qtdCritico = verficaPacienteCritico(lista);
    printf("%d\n", qtdCritico);
}

void  imprimeFila(Paciente* lista) {
    Paciente *p = lista;

    while (p != NULL){
        printf("\nPaciente - Chegada: %d, Tempo Crítico: %d\n", p->chegada, p->tempoCritico);
        p = p->proximo;
    };
}


Paciente *criaPaciente(){
    Paciente *p = (Paciente *) malloc(sizeof(Paciente));
    return p;
}


Paciente *addPacienteFila(int chegada, Paciente *lista, int tempoCritico) {
    Paciente *p = criaPaciente();
    p->chegada = chegada;
    p->tempoCritico = tempoCritico;
    p->proximo = NULL;

    if(lista == NULL) {
        lista = p;
    } else {
        Paciente *temp = lista;
        while (temp-> proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = p;
    }
    return lista;
}

int verficaPacienteCritico(Paciente *lista) {

    Paciente *p = lista;
    int cont = 0;
    int proxAtendimento = 7 * 60;
    int entrada = 0;
    while (p != NULL){
        entrada = p->chegada;
        while(entrada > proxAtendimento) {
            proxAtendimento +=30;
        }
        if ((p->chegada + p->tempoCritico) < proxAtendimento){
            cont++;
        }
        p = p->proximo;
        proxAtendimento += 30;
    } 
    return cont;
}