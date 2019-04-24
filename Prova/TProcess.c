#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#include "TProcess.h"

char *leituraString() {
	char buffer[1024];
	char *string = NULL;
	int tamanho = 0;

	// Leitura do teclado
	fgets(buffer, 1024, stdin);
	buffer[strlen(buffer) - 1] = '\0';   // Retira o \n da string

	// Aloca a string no tamanho certo
	tamanho = strlen(buffer) + 1;
	string = (char *)malloc(sizeof(char) * tamanho);

	if (string == NULL) {
		printf("Erro ao alocar memoria!\n");
		system("pause");
		exit(1);
	}

	// copia o buffer para a string
	strcpy(string, buffer);

	return string;
}

void initPCS(TProcess *processo) {
	processo->nome = NULL;
	processo->status = NULL;
	processo->memAloc = 0.00;
	processo->id = 0;
	processo->prioridade = 0;
}

void leituraPCS(TProcess *processo) {

	printf("Digite o nome: ");
	processo->nome = leituraString();

	printf("Digite o status: ");
	processo->status = leituraString();

	printf("Digite a quantidade de memoria utilizada: ");
	processo->memAloc = leituraString();

	printf("Digite a prioridade: ");
	scanf("%d ", &processo->prioridade);
	fflush(stdin);
}

void imprimePCS(TProcess *processo) {
	printf("Nome........: %s\n", processo->nome);
	printf("Status......: %s\n", processo->status);
	printf("Memoria.....: %s\n", processo->memAloc);
	printf("Prioridade..: %s\n", processo->prioridade);
}

void destroiPCS(TProcess *processo) {

	if (processo->nome != NULL) {    // Se o nome foi alocado
		free(processo->nome);
		processo->nome = NULL;
	}

	if (processo->status != NULL) {
		free(processo->status);
		processo->status = NULL;
	}

	if (processo->memAloc != NULL) {
		free(processo->memAloc);
		processo->memAloc = NULL;
	}

	processo->prioridade = 0;
}