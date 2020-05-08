/*
    Nome do programa: Tic Tac Toe
    Objetivo do programa: Fazer um jogo da velha para console
    Nome do programador: Lucas Zottis
    Data de cria��o: 08/05/2020
*/

// * Cabe�alhos *
#include <stdio.h>
#include <stdlib.h>

// * Estruturas *
typedef struct { // Dados sobre os players (a maquina conta como player e ser� inicializado no come�o do jogo);
	char nome[10]; // Nome do player, a maquina ser� COM;
	int partidas, vitorias, empates, derrotas; // Dados sobre partidas, vit�rias, empates e derrotas;
}Jogador;

// * Variaveis Globais *
char grade[]
Jogador p1; // Jogador 1
Jogador p2; // Jogador 2
Jogador com; // Jogador 3

// * Declara��o de fun��es *


int main()
{
    printf("Hello Tic Tac Toe!\n");
    return 0;
}
