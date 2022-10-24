#line 2 "Cassino Ritchie" // Redefine __LINE__ e __FILE__.
#include "jogos.h" /*| Macros FICHAS_INICIAIS, MENU, DIV, OPT, OS |
					 | Funções limpa();, blackjack();, corrida();, poker();, roleta();, slots();, jogadoresqtd(); |
					 | Arquivos de cabeçalho stdio.h, stdlib.h, locale.h, time.h | */
int main(void) {
	int escolha_jogo; // Armazena entrada referente ao jogo que será jogado.

	limpa(); // limpa tela
	printf("%s\tBem vindo(a) ao %s!%s", DIV,__FILE__, DIV); // Banner do cassino.

	printf("\nPressione enter...");
	getchar(); // Aguarda usuário teclar algo.
	limpa();
	// Menu principal, executado quando o usuário não deseja sair, digita um número inválido ou sai de um jogo.
	do {
		limpa();
		printf("%s\t\t Salão de Jogos%s", DIV, DIV);
		printf(MENU);
		scanf("%d", &escolha_jogo);
		limpa();
		switch(escolha_jogo) {
		case 1: //blackjack(); break;
		case 3: //poker(); break;
		case 4: //roleta();
			printf("%s\t\tEm desenvolvimento...%s", DIV, DIV);
			sleep(2);
			break;
		case 2: corrida(); break;
		case 5: slots();
		}
	} while (escolha_jogo != 6 || (escolha_jogo < 1 && escolha_jogo > OPT));
	printf("%s\t\tVolte sempre!%s", DIV, DIV); // Exibe mensagem final, quando o usuário desejar sair do cassino.

	return 0;
}
