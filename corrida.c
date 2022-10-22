#line 2 "Corrida de Cavalos Ritchie" // Redefine __LINE__ e __FILE__
#include "jogos.h" // Arquivo de cabeçalho principal

void corrida(void) { // Corrida de Cavalos
	printf("%s Bem vindo(a) ao %s!%s", DIV, __FILE__, DIV);

	srand(time(NULL)); // Define semente para rand();
	int xjogadores = jogadoresqtd(); // Recebe o retorno da quantidade de jogadores da função jogadoresqtd();
	int subtrai_jogadores = xjogadores; /* Variável controladora de laço, no qual finaliza o caça-níqueis
									       quando o número de jogadores for 0. */
	char jogadores[xjogadores][20]; // Armazena os nicks dos jogadores de acordo com sua quantidade
	int fichas[xjogadores]; // Fichas iniciais de cada jogador
	int avanco_cavalos[xjogadores];
	int avanco;
	char pista[xjogadores][21];

	for (int j = 0; j < xjogadores; j++) {
		for (int i = 0; i < 21; i++)
			pista[j][i] = '_';
	}

	printf("Nicks:\n");
	for (int i = 0; i < xjogadores; i++) { // Nicks dos jogadores
		printf("Jogador %d: ", i+1);
		scanf("%s", jogadores[i]);
		fichas[i] = 1000;
		avanco_cavalos[i] = 0;
		pista[i][avanco_cavalos[i]] = '►';
	}
	limpa();
	while (subtrai_jogadores) {
		for (int j = 0; j < xjogadores; j++) {
			printf("-> Jogador: %s\n-> Pista:\n|", jogadores[j]);
			for (int i = 0; i < 21; i++) {
				printf(" %c |", pista[j][i]);
			}
		}
		printf("%s Façam suas apostas!%s", DIV, DIV);
		printf("Jo");
	}
}
