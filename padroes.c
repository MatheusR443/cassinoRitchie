#include "jogos.h" // Arquivo de cabeçalho principal

void limpa(void) {/* Limpa a tela de acordo com o sistema operacional do usuario,
	   	   	   	   	 evitando programação adicional. */
	(OS == 1?system("clear"):system("cls"));
}
int jogadoresqtd(void) { // Retorna quantidade de jogadores e limpa a tela
	int jgdrs;
	printf("\nDigite o número de jogadores: ");
	scanf("%d", &jgdrs);
	limpa();
	return jgdrs;
}


