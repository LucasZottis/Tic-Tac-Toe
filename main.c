/*
    Nome do programa: Tic Tac Toe
    Objetivo do programa: Fazer um jogo da velha para console
    Nome do programador: Lucas Zottis
    Data de criação: 08/05/2020
*/

// * Cabeçalhos *
#include <stdio.h>
#include <stdlib.h>

// * Estruturas *
typedef struct { // Dados sobre os players (a maquina conta como player e será inicializado no começo do jogo);
	char nome[10]; // Nome do player, a maquina será COM;
	int partidas, vitorias, empates, derrotas; // Dados sobre partidas, vitórias, empates e derrotas;
}Jogador;

// * Variaveis Globais *
char grade[]
Jogador p1; // Jogador 1
Jogador p2; // Jogador 2
Jogador com; // Jogador 3

// * Declaração de funções *


int main()
{
    printf("Hello Tic Tac Toe!\n");
    return 0;
}
