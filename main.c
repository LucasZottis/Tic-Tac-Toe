/*
    Nome do programa: Tic Tac Toe
    Objetivo do programa: Fazer um jogo da velha para console
    Nome do programador: Lucas Zottis
    Data de criação: 08/05/2020
*/
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#define TAM 8

// Dados sobre os players (a maquina conta como player e será inicializado no começo do jogo);
typedef struct {
	// Nome do player, a maquina será COM;
	char name[10];
	// Dados sobre partidas, vitórias, empates e derrotas;
	int match, win, tie, lose;
}Player;
// grade do jogo;
char house[TAM];
// Referenciação dos players;
Player player1;
Player player2;
Player com;

/* Declaração das funções */
int Menu(void);
void GameMode(void);
void VersusCOM(void);
void VersusHuman(void);
int ExitProgram(void);
void InitHouses(void);
void Initiate(void);
void ShowHouses(void);
int HumanMove(int turn);
int IAMove(void);
int EmptyHouse(int spot, int turn);
int Verify(void);

int main() {
	// Inicializações;
	Initiate();
	// CONFIGURANDO PARA O IDIOMA PORTUGUES;
	setlocale(LC_ALL, "Portuguese");
	int i, j, leave;
	// Apresentação;
	char intro [5][40] = {
		"\n Olá!",
		"Prazer, eu sou o Cidão.",
		"Sejam bem vindos ao Tic Tac Toe.",
		"Espero que se divirtam.",
		"Tenham um bom jogo e boa sorte.\n",
	};
	printf("* TIC - TAC - TOE *\n");;
	for (i = 0; i < 5; i++) {
		printf(" ");
		for (j = 0; j < 40; j++) {
			printf("%c", intro[i][j]);
		}
		printf("\n");
	}
	system("pause");
	system("CLS");
	do {
        leave = Menu();
	} while (leave == 0);
	return 0;
}
// Menu Principal;
int Menu(void) {
	int menu;
	do{ // Menu principal;
		printf("* TIC - TAC - TOE *\n");
		printf("\n 1 - Jogar");
		printf("\n 2 - Estatísticas");
		printf("\n 0 - Fechar");
		printf("\n\n | Opção: ");
		scanf("%d", &menu);
		if (menu < 0 || menu > 2){
			printf("\n Opção inválida!");
			printf("\n Informe uma opção válida do menu.");
			sleep(2);
		}
		system("CLS");
	}while(menu < 0 || menu > 2);
	switch(menu){
		case 1: // Menu de seleção de modo de jogo;
			GameMode();
		break;
		case 2: // Quadro de dados sobre partidas;
			printf("Aqui terá dados sobre as partidas.");
			Menu();
		break;
		case 0: // Fechar programa;
            return ExitProgram();
		break;
	}
}
// Modo de jogo;
void GameMode(void){
	int menu;
	do{ // Menu modo de Jogo;
		printf("* TIC - TAC - TOE *\n");;
		printf("\n 1 - vs COM");
		printf("\n 2 - vs Player");
		printf("\n 0 - Voltar");
		printf("\n\n | Opção: ");
		scanf("%d", &menu);
		if (menu < 0 || menu > 2){
			printf("\n Opção inválida!");
			printf("\n Informe uma opção válida do menu.");
			sleep(2);
		}
		system("CLS");
	}while(menu < 0 || menu > 2);
	switch (menu){
		case 1: // Jogar vs COM;
			VersusCOM();
		break;
		case 2: // Jogar vs Player;
			VersusHuman();
		break;
		case 0: // Voltar para o menu principal;
			system("CLS");
		break;
	}
}
// Versus COM;
void VersusCOM(void) {
	int winner = 3;
	int turn = 1;
	InitHouses();
	setbuf(stdin, NULL);
	printf("* TIC - TAC - TOE *\n");
	printf("\n\n Player 1: ");
	gets(player1.name);
	system("CLS");
	do { // Execução do jogo;
		printf("* TIC - TAC - TOE *\n");
		ShowHouses();
		switch (turn) {
			case 1:
                turn = HumanMove(turn);
			break;
			case 2:
				turn = IAMove();
			break;
		}
		winner = Verify();
		system("CLS");
	} while (winner > 2);
	switch (winner) { // Verifica quem ganhou;
		case 1: // Player 1 ganhou!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s ganhou!!", player1.name);
		break;
		case 2: // Player 2 ganhou!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s ganhou!!", com.name);
		break;
		default: // Deu empate!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s e %s empataram!!", player1.name, com.name);
		break;
	}
	sleep(2);
	system("CLS");
}
// Versus Humano;
void VersusHuman(void) {
	int winner = 3;
	int turn = 1;
	InitHouses();
	setbuf(stdin, NULL);
	printf("* TIC - TAC - TOE *\n");
	printf("\n\n Player 1: ");
	gets(player1.name);
	printf("\n\n Player 2: ");
	gets(player2.name);
	system("CLS");
	do { // Execução do jogo;
		printf("* TIC - TAC - TOE *\n");
		ShowHouses();
		switch (turn) {
			case 1:
                turn = HumanMove(turn);
			break;
			case 2:
                turn = HumanMove(turn);
			break;
		}
		winner = Verify();
		system("CLS");
	} while (winner > 2);
	switch (winner) { // Verifica quem ganhou;
		case 1: // Player 1 ganhou!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s ganhou!!", player1.name);
		break;
		case 2: // Player 2 ganhou!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s ganhou!!", player2.name);
		break;
		default: // Deu empate!!
			printf("* TIC - TAC - TOE *\n");
			ShowHouses();
			printf("\n\n %s e %s empataram!!", player1.name, player2.name);
		break;
	}
	sleep(2);
	system("CLS");
}
// Sair programa;
int ExitProgram(void) {
	char leave;
	int setExit = 0;
	do { // Sair do programa;
		printf("* TIC - TAC - TOE *\n");
		printf("\n Deseja sair [S/N]? ");
		setbuf(stdin, NULL);
		scanf("%c", &leave);
		getchar();
		if ((leave == 's') || (leave == 'S')) {
			system("CLS");
			printf("* TIC - TAC - TOE *\n");
			printf("\n Tchau!!");
			sleep(1);
			return 1;
		} else {
			if ((leave == 'n') || (leave == 'N')) {
				system("CLS");
				return 0;
			} else {
				printf("\n Opção invalida!!");
			}
		}
		Sleep(750);
		system("CLS");
	} while ((leave != 's' && leave != 'S') || (leave != 'n' && leave != 'N'));
}
// Inicializador de grade;
void InitHouses(void) {
	int i;
	// Inicialização da grade;
	for (i = 0; i <= 9; i++) {
		house[i] = ' ';
	}
}
// Mostra grade;
void ShowHouses(void) {
	int i, count;
	printf("\n");
	printf(" ");
	for (i = 0; i <= 2; i++) {
		printf("|%c|", house[i]);
	}
	printf("\n");
	printf(" ");
	for (i = 3; i <= 5; i++) {
		printf("|%c|", house[i]);
	}
	printf("\n");
	printf(" ");
	for (i = 6; i <= 8; i++) {
		printf("|%c|", house[i]);
	}
}
// Inicializações;
void Initiate(void){
	// Player 1;
	player1.match = 0;
	player1.win = 0;
	player1.tie = 0;
	player1.lose = 0;
	// Player 2;
	player2.match = 0;
	player2.win = 0;
	player2.tie = 0;
	player2.lose = 0;
	// COM;
	strcpy(com.name, "Jarvas");
	com.match = 0;
	com.win = 0;
	com.tie = 0;
	com.lose = 0;
	// Inicialização da grade;
	InitHouses();
}
// Jogada humana;
int HumanMove(int turn) {
	int spot, keepItOn;
	switch (turn) {
		case 1:
            printf("\n\n -> %s", player1.name);
            printf("\n Local [1-9]: ");
            scanf("%d", &spot);
            keepItOn = EmptyHouse(spot, turn);
		break;
		case 2:
            printf("\n\n -> %s", player2.name);
            printf("\n Local [1-9]: ");
            scanf("%d", &spot);
            keepItOn = EmptyHouse(spot, turn);
        break;
	}
	return keepItOn;
}
// Jogada IA;
int IAMove(void) {
	int spot, i;
	// Definindo casa para jogar;
	srand(time(NULL));
	spot = rand() % TAM;
	// Verifica se local está ocupado;
	if (house[spot] == ' ') {
		house[spot] = 'O';
        return 1;
	} else {
		char dots[3] = "...";
		char *s = dots;
		printf("\n\n -> %s está Pensando", com.name);
		for (i = 0; i < strlen(dots); i++) {
			printf("%c", *s);
			Sleep(200);
		}
		return 2;
	}
}
// Verifica se local está ocupado;
int EmptyHouse(int spot, int turn) {
	switch (turn) {
		case 1:
            if (house[spot - 1] == ' '){
                house[spot - 1] = 'X';
                // Retorna 2 para passar o turno após jogado com sucesso;
                return 2;
            } else {
                printf(" Ocupado!!");
                Sleep(750);
                // Retorna 1 para não passar o turno sem jogar
                return 1;
            }
		break;

		case 2:
            if (house[spot - 1] == ' '){
                house[spot - 1] = 'O';
                // Retorna 2 para passar o turno após jogado com sucesso;
                return 1;
            } else {
                printf(" Ocupado!!");
                Sleep(750);
                // Retorna 1 para não passar o turno sem jogar
                return 2;
            }
		break;
	}
}
// Verifica se alguem ganhou;
int Verify(void) {
    int i;
    // Verifica linhas;
    for(i=0; i<3; i++){
        if(house[i*3] == house[i*3+1] && house[i*3] == house[i*3+2]){
            if(house[i*3] == 'X') return 1;
            if(house[i*3] == 'O') return 2;
        }
    }
    // Verifica Colunas:
    for(i=0; i<3; i++){
        if(house[i] == house[i+3] && house[i] == house[i+6]){
            if(house[i] == 'X') return 1;
            if(house[i] == 'O') return 2;
        }
    }
    // Verifica Diagonal Principal:
    if(house[0] == house[4] && house[0] == house[8]){
        if(house[0] == 'X') return 1;
        if(house[0] == 'O') return 2;
    }
    // Verifica Diagonal Secundária
    if(house[2] == house[4] && house[2] == house[6]){
        if(house[2] == 'X') return 1;
        if(house[2] == 'O') return 2;
    }
    char tie = 1;
    for (i = 0; i <= TAM; i++) {
    	if (house[i] == ' ') {
    		tie = 0;
    		break;
		}
	}
	if (tie) return 0;
    return 3;
}
