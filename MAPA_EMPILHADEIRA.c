#include <stdio.h>
#include <stdlib.h>

#define TAM 8

typedef struct t_pilha {
	int dados[TAM];
	int ini;
	int topo;
}t_pilha;

t_pilha pilha1, pilha2;

// Função para empilhar os números do R.A.
void empilha(int numero, t_pilha *p) {
	// Verificando se a pilha está cheia
	if (p->topo == TAM) {
		printf("A pilha está cheia, não é possível empilhar mais nenhum elemento.");
		printf("\nAperte ENTER para finalizar...");
		getchar();
	} else {
		p->dados[p->topo] = numero;
		p->topo++;
	}
}

// Função para desempilhar os números do R.A. e empilhá-los, de maneira inversa, na segunda pilha
int desempilha(t_pilha *p) {
	int backup;
	
	// Verificando se a pilha está vazia
	if (p->topo == pilha1.ini) {
		printf("A pilha está vazia, não há nada para desempilhar.");
		printf("\nAperte ENTER para finalizar...");
		getchar();
	} else {
		p->topo--;
		backup = p->dados[p->topo];
		p->dados[p->topo] = 0;
		empilha(backup, &pilha2);
	}
}	

void imprimir(t_pilha *p){
	printf("\n");
	int i;
	for (i=0; i<TAM; i++) {
		printf("%d ", p->dados[i]);
	}
	printf("\n\n");
}

int main() {
	pilha1.topo = 0;
	pilha1.ini = 0;
	
	pilha2.topo = 0;
	pilha2.ini = 0;
	
	empilha(1, &pilha1);
	empilha(9, &pilha1);
	empilha(4, &pilha1);
	empilha(5, &pilha1);
	empilha(7, &pilha1);
	empilha(9, &pilha1);
	empilha(7, &pilha1);
	empilha(5, &pilha1);
	imprimir(&pilha1);
	
	desempilha(&pilha1);
	desempilha(&pilha1);
	desempilha(&pilha1);
	desempilha(&pilha1);	
	desempilha(&pilha1);	
	desempilha(&pilha1);
	desempilha(&pilha1);
	desempilha(&pilha1);
	imprimir(&pilha2);
	printf("Aperte ENTER para finalizar...");
	getchar();
	
}
