#pragma once
#ifndef _TMANAGER_H_
#define _TMANAGER_H_

#include "TProcess.h"

// Declaracao de constantes
#define ARQUIVO "processos.txt"

// Declaracao de tipos
typedef struct {
	TProcess *processos;
	int tamanho;
} TManager;

// Declaracao das operacoes

void initManager(TManager *gerenciador);
void salvaManager(TManager *gerenciador);
void carregaManager(TManager *gerenciador);
void destroiManager(TManager *gerenciador);
void imprimeManager(TManager *gerenciador);
void adicionaProcesso(TManager *gerenciador, TProcess processo);

#endif