/* ============================================================
 * = PROGRAMA Gerenciador de processos                        =
 * ============================================================
 * - Gerenciador de processos simples                         -
 * -                                                          -
 * - Autor: Kauam Costa			                              -
 * - Data: 21/04/2019                                         -
 * ------------------------------------------------------------ */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "TManager.h"
#pragma warning(disable : 4996)

 /* ------------------------------------------------------------
  * - PROGRAMA PRINCIPAL                                       -
  * ------------------------------------------------------------ */
int main() {

	//// Adiciona 2 processos no gerenciador e salva em disco
	TManager gerenciador;
	TProcess processo1;
	TProcess processo2;

	initManager(&gerenciador);

	/* Comentado para nao cadastrar novamente
	initContato(&contato1);
	initContato(&contato2);

	leituraContato(&contato1);
	leituraContato(&contato2);

	adicionaContato(&agenda, contato1);
	adicionaContato(&agenda, contato2);

	salvaAgenda(&agenda);
	*/

	carregaManager(&gerenciador);
	imprimeManager(&gerenciador);



	// Finaliza o programa com sucesso
	system("pause");
	return 0;
}