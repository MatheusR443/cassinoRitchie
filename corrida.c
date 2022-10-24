#line 2 "Corrida de Cavalos Ritchie" // Redefine __LINE__ e __FILE__
#include "jogos.h" // Arquivo de cabeçalho principal

void contagem();

void corrida(void) { // Corrida de Cavalos
	printf("%s   Bem vindo(a) ao %s!%s", DIV, __FILE__, DIV);

	srand(time(NULL)); // Define semente para rand();
	int xjogadores = jogadoresqtd(); // Recebe o retorno da quantidade de jogadores da função jogadoresqtd();
	int subtrai_jogadores = xjogadores; /* Variável controladora de laço, no qual finaliza o caça-níqueis
									       quando o número de jogadores for 0. */
	char jogadores[xjogadores][20]; // Armazena os nicks dos jogadores de acordo com sua quantidade
	int fichas[xjogadores]; // Fichas iniciais de cada jogador
	int cavalos[xjogadores];
	int apostas[xjogadores];
	int avanco_cavalos[] = { 0, 0, 0};
	int vencedor = 0;
	char situacao[20];
	char pista[3][21];

	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 21; i++)
			pista[j][i] = '_';
		pista[j][0] = '>';
	}

	printf("%s\t\t\tNicks%s", DIV, DIV);
	for (int i = 0; i < xjogadores; i++) { // Nicks dos jogadores
		printf("\nJogador %d: ", i+1);
		scanf("%s", jogadores[i]);
		fichas[i] = 1000;
	}
	limpa();
	while (subtrai_jogadores) {
		limpa();
		for (int j = 0; j < 3; j++) {
			for (int i = 0; i < 21; i++)
				pista[j][i] = '_';
			pista[j][0] = '>';
		}
		for (int j = 0; j < 3; j++) {
			printf("\n\n-> Cavalo %d <-", j+1);
			printf("%s",LINHA_MAIOR);
			putchar('|');
			for (int i = 0; i < 21; i++)
				printf(" %c |", pista[j][i]);
		}
		printf("%s\t\tFaçam suas apostas!%s", DIV, DIV);
		for (int j = 0; j < xjogadores; j++) {
			if (fichas[j] > 0) {
				printf("\nJogador: %s\nFichas: %d\nCavalo (1, 2, 3): ", jogadores[j], fichas[j]);
				scanf("%d", &cavalos[j]);
				printf("Apostar fichas: ");
				scanf("%d", &apostas[j]);
				fichas[j]-=apostas[j];
				putchar('\n');
			}
		}
		limpa();
		contagem();
		while (vencedor == 0) {
			limpa();
			for (int i = 0; i < 3; i++) {
				pista[i][avanco_cavalos[i]] = '_';
				avanco_cavalos[i]+= rand() % 4 + 1;
				avanco_cavalos[i] = (avanco_cavalos[i] > 20?20:avanco_cavalos[i]);
				pista[i][avanco_cavalos[i]] = '>';
				if (avanco_cavalos[i] == 20)
					vencedor = i+1;
			}
			for (int j = 0; j < 3; j++) {
				printf("\n\n -> Cavalo %d <-", j+1);
				printf(LINHA_MAIOR);
				for (int i = 0; i < 21; i++)
					printf(" %c |", pista[j][i]);
			}
			printf(LINHA_MAIOR);
			sleep(2);
		}
		printf("%s\t\t  Resultados%s", DIV, DIV);
		for (int j = 0; j < xjogadores; j++) {
			if (cavalos[j] == vencedor) {
				fichas[j]+=apostas[j]*2;
				strcpy(situacao, "Vitória");
			} else
				strcpy(situacao, "Derrota");
			printf("%s\n\tJogador: %s\n\tSituação: %s\n\tFichas: %d\n%s"
					, LINHA, jogadores[j], situacao, fichas[j], LINHA);
			if (fichas[j] == 0)
				subtrai_jogadores--;
			sleep(5);
		}
	}
	limpa();
	printf("%s  Corrida de cavalos vazia, volte sempre!%s", DIV, DIV);
	sleep(3);
}

void contagem(void) {
	for (int i = 10; i > 0; i--) {
		printf("%s\t\tContagem regressiva: %d%s", DIV, i, DIV);
		sleep(1);
		limpa();
	}
}