#include <stdio.h>

#define POLICIA 'D'
#define LADRAO 'L'
#define NULL_CHAR '-'

int indiceArray( int i, int j, int nColunas) {
	return i * nColunas + j;
}


void lerArray (char *array, int nColunas) {
	int i, j;
	
	for(i=0; i<nColunas; i++) {
		for(j=0; j<nColunas; j++) {
			scanf("%s", &array[indiceArray(i, j, nColunas)]);
		}
	}
}

void limpaArray(char *array, int size) {
	int i;
	for(i=0; i<size; i++) {
		array[i] = ' ';
	}
}

int buscaPorLinha(char *matriz, int line, int nColunas, int numberOfHouseToArrest) {
	int countDistancia = 0;
	int j;
	for(j = 0; j < nColunas; j++) {
		if(matriz[indiceArray(line, j, nColunas)] == POLICIA) {
			int i = 1;
			while((i <= numberOfHouseToArrest) && ((j - i) >= 0)) {
				if(matriz[indiceArray(line, j - i, nColunas)] == LADRAO) {
					matriz[indiceArray(line, j, nColunas)] = NULL_CHAR;
					matriz[indiceArray(line, j - i, nColunas)] = NULL_CHAR;
					countDistancia ++;
					break;
				}
				i ++;
			}
		}
			
		if(matriz[indiceArray(line, j, nColunas)] == POLICIA) {
			int i = 1;
			while((i <= numberOfHouseToArrest) && ((j + i) < nColunas)) {
				if(matriz[indiceArray(line, j + i, nColunas)] == LADRAO) {
					matriz[indiceArray(line, j, nColunas)] = NULL_CHAR;
					matriz[indiceArray(line, j + i, nColunas)] = NULL_CHAR;
					countDistancia ++;
					break;
				}
				i ++;
			}
		}
	}
	
	return countDistancia;
}

int buscaPorColuna(char *matriz, int column, int nLinhas, int numberOfHouseToArrest) {
	int countDistancia = 0;
	int i;
	for(i = 0; i < nLinhas; i++) {
		if(matriz[indiceArray(i, column, nLinhas)] == POLICIA) {
			int j = 1;
			while((j <= numberOfHouseToArrest) && ((i - j) >= 0)) {
				if(matriz[indiceArray(i - j, column, nLinhas)] == LADRAO) {
					matriz[indiceArray(i, column, nLinhas)] = NULL_CHAR;
					matriz[indiceArray(i - j, column, nLinhas)] = NULL_CHAR;
					countDistancia ++;
					break;
				}
				i ++;
			}
		}
			
		if(matriz[indiceArray(i, column, nLinhas)] == POLICIA) {
			int j = 1;
			while((j <= numberOfHouseToArrest) && ((i + j) < nLinhas)) {
				if(matriz[indiceArray(i + j, column, nLinhas)] == LADRAO) {
					matriz[indiceArray(i, column, nLinhas)] = NULL_CHAR;
					matriz[indiceArray(i + j, column, nLinhas)] = NULL_CHAR;
					countDistancia ++;
					break;
				}
				i ++;
			}
		}
	}
	
	return countDistancia;
}

int contaLadrao(char *matriz, int nColunas, int numberOfHouseToArrest) {
	int countDistancia = 0;
	int i;
	for(i=0; i < nColunas; i++) {
		countDistancia = countDistancia + buscaPorLinha(matriz, i, nColunas, numberOfHouseToArrest);
	}
	
	int j;
	for(j=0; j < nColunas; j++) {
		countDistancia = countDistancia + buscaPorColuna(matriz, j, nColunas, numberOfHouseToArrest);
	}
	
	return countDistancia;
}

int main() {
	
	int n;
	scanf("%d", &n);
	
	int i;
	for(i=0; i<n; i++) {
		int linha, distancia;
		scanf("%d %d", &linha, &distancia);
		
		int tam = linha * linha;
		
		char matriz[tam];
		limpaArray(matriz, linha);
		lerArray(matriz, linha);
		
		printf("%d\n", contaLadrao(matriz, linha, distancia));
		
	}
	
	return 0;
}

