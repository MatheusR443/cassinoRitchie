#line 2 "Roleta Ritchie" // Redefine __LINE__ e __FILE__
#include "jogos.h" // Arquivo de cabeçalho principal

void roleta(void) { // Roleta
	printf("%s Bem vindo(a) ao %s!%s", DIV, __FILE__, DIV);

	srand(time(NULL)); // Define semente para rand();
	int xjogadores = jogadoresqtd(); // Recebe o retorno da quantidade de jogadores da função jogadoresqtd();
	char jogadores[xjogadores][20]; // Armazena os nicks dos jogadores de acordo com sua quantidade
	int fichas[xjogadores]; // Fichas iniciais de cada jogador

	printf("Nicks:\n");
	for (int i = 0; i < xjogadores; i++) { // Nicks dos jogadores
		printf("Jogador %d: ", i+1);
		scanf("%s", jogadores[i]);
		fichas[i] = 1000;
	}
}
