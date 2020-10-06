#include <stdio.h>
#include <stdlib.h>
#include "abb.h"

void inicializar (ArvoreBB **raiz) {
	*raiz = NULL;
}

int inserir_interativo (ArvoreBB **raiz, int chave, float val) {
	ArvoreBB *no = (ArvoreBB*) malloc(sizeof(ArvoreBB));
	(*no).conteudo = val;
	(*no).chave = chave;
	(*no).esq = NULL;
	(*no).dir = NULL;
	(*no).pai = NULL;

	if (*raiz == NULL) {
		*raiz = no;
		return 1;
	}

	ArvoreBB *aux = *raiz, *aux2 = NULL;

	while (aux != NULL) {
		aux2 =  aux;
		
		if (chave < (*aux).chave) 
			aux = (*aux).esq;
		else if (chave > (*aux).chave)
			aux = (*aux).dir;
		else
			return 0;
	}

	if (chave > (*aux2).chave)
		(*aux2).dir = no;
	else 
		(*aux2).esq = no;

	(*no).pai = aux2;

	return 1;
}

int inserir_recursivo (ArvoreBB **raiz, int chave, float val) {
	if (*raiz == NULL) {
		*raiz = (ArvoreBB*) malloc(sizeof(ArvoreBB));
		(**raiz).conteudo = val;
		(**raiz).chave = chave;
		(**raiz).dir = NULL;
		(**raiz).esq = NULL;
		(**raiz).pai = NULL;

		return 1;
	} else {
		if (chave > (**raiz).chave) {
			if (inserir_recursivo(&(**raiz).dir, chave, val)) {
				((**raiz).dir)->pai = *raiz;

				return 1;
			}
		}			
		else if (chave < (**raiz).chave) {
			if (inserir_recursivo(&(**raiz).esq, chave, val)) {
				((**raiz).esq)->pai = *raiz;
			
				return 1;
			}
		}
		else {
			return 0;
		}
	}

	return 0;
}

float buscar_interativo (ArvoreBB *raiz, int chave) {
	if (raiz == NULL) {
		printf("Error: raiz da arvore é nula\n");
		return 99999.99;
	}
	
	ArvoreBB *aux = raiz;

	while (aux != NULL) {
		if (chave > (*aux).chave){
			aux = (*aux).dir;
		}
		else if (chave < (*aux).chave){
			aux = (*aux).esq;
		}
		else {
			printf("O nó de chave %d tem conteúdo %.2f\n", (*aux).chave, (*aux).conteudo);
			return 1;
		}
	}

	printf("Error: nó não existe\n");
	return 99999.99;
}


ArvoreBB *sucessor(ArvoreBB *no, int chave) {
	ArvoreBB *aux2, *aux = buscar(no, chave);

	if ((*aux).dir != NULL || (*aux).pai == NULL) {
		return minimo((*aux).dir);
	
	}
	else {
		if ((*aux).pai->esq == aux){
			return (*aux).pai;
		}
		else {
			ArvoreBB *aux2 = (*aux).pai;
			
			while ((*aux2).pai != NULL && (*aux2).pai->dir == aux2)
				aux2 = (*aux2).pai;

			return (*aux2).pai;
		}
	}
}

ArvoreBB *minimo(ArvoreBB *no) {
	if (no == NULL) {
		printf("Error: arvore vazia\n");
		return 0;
	}

	ArvoreBB *aux = no;

	while ((*aux).esq != NULL)
		aux = (*aux).esq;
	
	return aux;
}

ArvoreBB *maximo(ArvoreBB *no) {
	if (no == NULL) {
		printf("Error: arvore vazia\n");
		return 0;
	}

	ArvoreBB *aux = no;

	while ((*aux).dir != NULL)
		aux = (*aux).dir;
	
	return aux;
}

ArvoreBB *buscar(ArvoreBB *raiz, int chave) {
	ArvoreBB *aux = raiz;

	while (aux != NULL && (*aux).chave != chave)
		if (chave > (*aux).chave)
			aux = (*aux).dir;
		else
			aux = (*aux).esq;
		
	return aux;
}