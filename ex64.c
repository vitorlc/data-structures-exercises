#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct lista, que vai servir de base para a minha pilha.
typedef struct lista{
	char dado[210];
	struct lista *next;
}Lista;

// Crio um nó e retorno ele alocado pra lista.
Lista *cria_no(char *x){
	Lista *no = (Lista*) malloc(sizeof(Lista));
	strcpy(no->dado, x);
	no->next = NULL;
	return no;
}

// Insiro no inicio da lista, como uma pilha deve ser.

Lista *insere_inicio(Lista *L, char *x){
	Lista *tmp = cria_no(x);
	tmp->next = L;
	return tmp;
}

// Removo um item do topo da pilha.
Lista *remover(Lista *L){
	if(L == NULL) return NULL;
	Lista *tmp = L->next;
	free(L);
	return tmp;
}

// Retorno o conteudo do topo da pilha.
char *topo(Lista *P){
	return P->dado;
}

// Verifico se a lista esta vazia.
int vazia(Lista *P){
	if(P == NULL) return 1;
	return 0;
} 

// Desaloco a pilha

void limpa(Lista *L){
	if(L == NULL) return;
	limpa(L->next);
	free(L);
	L = NULL;
}

int main(){
	int t, i;
	char s[210];
	Lista *dir, *loc;
	// Leio a quantidade de casos testes e itero por ele.
	scanf("%d", &t);
	while(t--){
		// Reseto as variaveis.
		dir = loc = NULL;
		// Leio ate aparecer escola, se for direcao, insiro na pilha de direcao, se não insiro na de localidades.
		while(scanf(" %s", s) && strcmp(s,"ESCOLA") != 0){
			if(strcmp(s, "ESQUERDA") == 0 || strcmp(s,"DIREITA") == 0){
				dir = insere_inicio(dir, s);
			}
			else{
				loc = insere_inicio(loc, s);
			}
		}
		// Enquanto as direcoes nao for vazio, entro nesse loop.
		while(!vazia(dir)){
			// Se a direcao original for esquerda, preciso virar pra direita.
			if(strcmp(topo(dir), "ESQUERDA") == 0){
				printf("Vire a DIREITA na ");
				// Se for a ultima iteracao, viro pra casa.
				if(vazia(loc)) printf("sua CASA.\n");
				else printf("rua %s.\n", topo(loc));
	
			}
			// Mesma coisa pro lado esquerdo.
			else{
				printf("Vire a ESQUERDA na ");
				if(vazia(loc)) printf("sua CASA.\n");
				else printf("rua %s.\n", topo(loc));
			}
			// Removo o topo da lista
			loc = remover(loc);
			dir = remover(dir);
		}
		// Limpo a lista
		limpa(dir);
		limpa(loc);
	}
}