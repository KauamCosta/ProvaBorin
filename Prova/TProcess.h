#ifndef _TPROCESS_H_
#define _TPROCESS_H_

// -----------------------------
// Declaracao de tipos de dados
// -----------------------------
typedef struct process {
	int id,
		prioridade;
	char*nome,
		status,
		memAloc;
} TProcess;

// ----------------------
// Declaracao de funcoes
// ----------------------

void initPCS(TProcess *processo);
void leituraPCS(TProcess *processo);
void imprimePCS(TProcess *processo);
void destroiPCS(TProcess *processo);

#endif