#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable : 4996)

#include "TManager.h"

char *leituraStringArq(FILE *fp) {
	char buffer[1024];
	char *string = NULL;
	int tamanho = 0;

	// Leitura do teclado
	fgets(buffer, 1024, fp);
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



void initManager(TManager *gerenciador) {
	gerenciador->processos = (TManager *)malloc(sizeof(TManager) * 1000);

	if (gerenciador->processos == NULL) {
		printf("Erro ao alocar memoria!");
		system("pause");
		exit(1);
	}

	gerenciador->tamanho = 0;
}

void destroiManager(TManager *gerenciador) {
	free(gerenciador->processos);
	gerenciador->processos = NULL;
	gerenciador->tamanho = -1;
}


void salvaManager(TManager *gerenciador) {
	int i = 0;

	// 1. Abre o arquivo
	//      fopen("<nome_do_arquivo>", "<modo>");
	//      modo:   w - abre o arquivo para escrita apartir do começo
	//              r - abre o arquivo para leitura
	//              a - abre o arquivo para escrever a partir do final
	FILE *fp = fopen(ARQUIVO, "a+");

	if (fp == NULL) {
		printf("Erro ao abrir o arquivo %s\n", ARQUIVO);
		system("pause");
		exit(2);
	}

	// 2. Manipula o arquivo   
	for (i = 0; i < gerenciador->tamanho; i++) {
		TProcess processo = gerenciador->processos[i];

		fprintf(fp, "%s\n", processo.nome);
		fprintf(fp, "%s\n", processo.status);
		fprintf(fp, "%s\n", processo.memAloc);
		fprintf(fp, "%d\n", processo.prioridade);
	}

	// 3. Fecha o arquivo
	fclose(fp);
}

void carregaManager(TManager *gerenciador) {

	// 1. Abre o arquivo
	FILE *fp = fopen(ARQUIVO, "r");

	if (fp == NULL) {
		printf("Erro ao abrir o arquivo\n");
		system("pause");
		exit(2);
	}

	// 2. Manipula o arquivo

	// Enquanto nao for final de arquivo
	while (!feof(fp)) {
		char buffer[1024];
		TProcess processo;

		processo.nome = leituraStringArq(fp);
		if (feof(fp)) { break; }

		processo.status = leituraStringArq(fp);
		processo.memAloc = leituraStringArq(fp);

		fscanf(fp, "%d", &processo.prioridade);
		fscanf(fp, "%c", &buffer[0]);

		// Adiciona um novo contato no final do vetor
		adicionaProcesso(gerenciador, processo);
	}

	// 3. Fecha o arquivo
	fclose(fp);

}

void adicionaProcesso(TManager *gerenciador, TProcess processo) {
	gerenciador->processos[gerenciador->tamanho] = processo;
	gerenciador->tamanho++;
}

void imprimeManager(TManager *gerenciador) {
	int i = 0;

	for (i = 0; i < gerenciador->tamanho; i++) {
		imprimePCS(&gerenciador->processos[i]);
		printf("\n");
	}
}
