#line 2 "Caça-Níqueis Ritchie" // Redefine __LINE__ e __FILE__
#include "jogos.h" // Arquivo de cabeçalho principal

void manual(); // Manual de regras do caça-níqueis
void animacao(); // Animação de sorteio do caça-níqueis
float pontuacao(); /* Contém definições de ganho das apostas de acordo com o manual,
				      retornando o multiplicador que será aplicado às apostas. */

void slots(void) { // Função principal do Caça-Níqueis

	printf("%s Bem vindo(a) ao %s!%s", DIV, __FILE__, DIV);
	manual(); // Exibe manual de regras

	srand(time(NULL)); // Define semente para rand();
	int xjogadores = jogadoresqtd(); // Recebe o retorno da quantidade de jogadores da função jogadoresqtd();
	int subtrai_jogadores = xjogadores; /* Variável controladora de laço, no qual finaliza o caça-níqueis
									       quando o número de jogadores for 0. */
	char jogadores[xjogadores][20]; // Armazena os nicks dos jogadores de acordo com sua quantidade
	int fichas[xjogadores]; // Fichas iniciais de cada jogador
	int sorteio_jogador[xjogadores][3]; // Armazena os 3 números sorteados de cada jogador
	int apostas[xjogadores]; // Armazena a quantidade de fichas apostadas por cada jogador
	float multi; // Recebe o retorno do multiplicador do jogador da função pontuacao();

	printf(" -> Nicks <-\n");
	for (int i = 0; i < xjogadores; i++) { // Nicks dos jogadores
		printf("Jogador %d: ", i+1);
		scanf("%s", jogadores[i]);
		fichas[i] = FICHAS_INICIAIS; // Atribui fichas iniciais de acordo com a constante FICHAS_INICIAIS
	}
	limpa();
	while (subtrai_jogadores) { // Enquanto existir jogadores com fichas
		printf("%s Façam suas apostas!%s", DIV, DIV); // Apostas
		for (int i = 0; i < xjogadores; i++) {
			if (fichas[i] > 0) {
				do {
					printf("Jogador %s\nFichas: %d\n", jogadores[i], fichas[i]);
					printf("Apostar fichas: ");
					scanf("%d", &apostas[i]);
				} while (apostas[i] > fichas[i]); // Valida aposta
				putchar('\n');
				fichas[i]-=apostas[i]; // Subtrai as fichas atuais pela aposta feita
			}
		}
		limpa();
		animacao(); // Exime animação de sorteio
		for (int i = 0; i < xjogadores; i++) {
			if (apostas[i] > 0) { // Garante que quem não apostou, não participe da rodada
				for (int j = 0; j < 3; j++)
					sorteio_jogador[i][j] = rand() % 7 + 1; // Sorteia os números de 1 a 7
				printf(DIV);
				// Envia os números sorteados e retorna multiplicador
				multi = pontuacao(sorteio_jogador[i][0], sorteio_jogador[i][1], sorteio_jogador[i][2]);
				apostas[i]*=multi; // Calcula ganhos
				fichas[i]+=apostas[i]; // Adiciona ganhos
				printf("Jogador: %s\nFichas: %d\n", jogadores[i], fichas[i]);
				if (fichas[i] == 0) // Remove jogadores
					subtrai_jogadores--;
				printf(DIV);
				sleep(5); // Aguarda 5 segundos
				limpa();
			}
		}
	}
	printf("%s Caça-Níqueis vazio, volte sempre!%s", DIV, DIV);
	sleep(3);
}

void manual(void) { // Manual de regras
	printf("\t\t| MANUAL |%s - O caça-níqueis contém 3 slots\n   com números de 1 a 7.%s"
				" - Trinca Máxima: | 7 | 7 | 7 |\n"
				" - Prêmio: 7x%s"
				" - Trinca: | x | x | x |, sendo x menor que 7\n"
				" - Prêmio: 6x%s"
				" - Par: | x | x | y |, | x | y | x |, | y | x | x |\n"
				" - Prêmio: 5x%s"
				" - Sequência Alta: | 5 | 6 | 7 |, | 4 | 5 | 6 |\n"
				" - Prêmio: 4x/3x%s"
				" - Sequência Média: | 3 | 4 | 5 |, | 2 | 3 | 4 |\n"
				" - Prêmio: 2x/1.5x%s"
				" - Sequência Baixa: | 1 | 2 | 3 |\n"
				" - Prêmio: 1x%s"
				" - Números Aleatórios: | x | y | z |\n"
				" - Prêmio: 0x%s", LINHA, LINHA, LINHA, LINHA, LINHA, LINHA, LINHA, LINHA, DIV);
}

float pontuacao(int sorteio_jogador1, int sorteio_jogador2, int sorteio_jogador3) { // Ganhos
	float multiplicador;

	if (sorteio_jogador1 == 7
		&& sorteio_jogador2 == 7
		&& sorteio_jogador3 == 7) {
					printf("\nTrinca máxima!\n"); // 777
					multiplicador = 7;
		} else if (sorteio_jogador1 == sorteio_jogador2
			       && sorteio_jogador2 == sorteio_jogador3) {
					printf("\nTrinca!\n"); // xxx
					multiplicador = 6;
		}
		else if (sorteio_jogador1 == sorteio_jogador2
				|| sorteio_jogador1 == sorteio_jogador3
				|| sorteio_jogador2 == sorteio_jogador3) {
					printf("\nPar!\n"); // xxy, xyx, yxx
					multiplicador = 5;
		}
		else if (sorteio_jogador1 == 5
				&& sorteio_jogador2 == 6
				&& sorteio_jogador3 == 7) {
					printf("\nSequência alta!\n"); // 567
					multiplicador = 4;
		}
		else if (sorteio_jogador1 == 4
				&& sorteio_jogador2 == 5
				&& sorteio_jogador3 == 6) {
					printf("\nSequência alta!\n"); // 456
					multiplicador = 3;
		}
		else if (sorteio_jogador1 == 3
				 && sorteio_jogador2 == 4
				 && sorteio_jogador3 == 5) {
					printf("\nSequência média!\n"); // 345
					multiplicador = 2;
		}
		else if (sorteio_jogador1 == 2
				&& sorteio_jogador2 == 3
				&& sorteio_jogador3 == 4) {
					printf("\nSequência média!\n"); // 234
					multiplicador = 1.5;
		}
		else if (sorteio_jogador1 == 1
				 && sorteio_jogador2 == 2
				 && sorteio_jogador3 == 3) {
					printf("\nSequência baixa!\n"); // 123
					multiplicador = 1;
		}
		else {
					printf("\nNúmeros aleatórios...\n"); // xyz
					multiplicador = 0;
		}
	printf("Resultado: | %d | %d | %d |\n", sorteio_jogador1, sorteio_jogador2, sorteio_jogador3); // Imprime resultado
	return multiplicador;
}

void animacao(void) { // Animação de sorteio
	for (int i = 7; i > 0; i--) {
		for (int j = 7; j > 0; j--) {
			for (int k = 7; k > 0; k--) {
				printf("%s Girando Caça-Níqueis Ritchie!%s", DIV, DIV);
				printf("\n\t\t| %d | %d | %d |\n", j, i, k);
				usleep(10000);
				limpa();
			}

		}
	}
}
