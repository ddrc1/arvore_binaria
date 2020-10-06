#include <stdio.h>
#include <stdlib.h>
#include "abb.c"

int main(int argc, char const *argv[]) {
	ArvoreBB *raiz;

	inicializar(&raiz);

	srand(time(NULL));
	
	for(int i = 0; i < 500000; i++)
		inserir_recursivo(&raiz, rand(), (rand()%99999)/100.0 );	
	
	for(int j = 0; j < 500000; j++)
		inserir_interativo(&raiz, rand(), (rand()%99999)/100.0 );	

	listar_elementos(raiz);

	return 0;
}