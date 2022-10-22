#include <stdio.h> // Contém printf();, scanf();
#include <stdlib.h> // Contém rand();, srand();
#include <locale.h> // Contém setlocale();
#include <time.h> // Contém time();, sleep();, usleep();, NULL.

#ifdef __linux__ // Define macro de sistema operacional (1 = Linux/2 = Outro)
#define OS 1
#else
#define OS 2
#endif

#define DIV "\n==================================================\n" // Divisória genérica
#define LINHA "\n--------------------------------------------------\n"
#define MENU "1)Blackjack\n2)Corrida de cavalos\n3)Poker\n4)Roleta\n5)Caça-níqueis\n6)Sair\n--> " // Menu do cassino
#define OPT 6 // Quantidade máxima de opções de menu
#define FICHAS_INICIAIS 1000 // Definição de fichas iniciais dos jogadores para todos os jogos

void limpa(); // padroes.c
void blackjack(); // blackjack.c
void corrida(); // corrida.c
void poker(); // poker.c
void roleta(); // roleta.c
void slots(); // slots.c
int jogadoresqtd(); // padroes.c
