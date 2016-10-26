#ifndef INICIALIZAR_H_INCLUDED
#define INICIALIZAR_H_INCLUDED
#include "moviment.h"

void start_snake(char * movimento, char * possivelmovimento, Tipo_Cont * contador,TIPO_OBJETO * apple, int * size_snake,
                 int posicao[2][MAXSNAKE], char matriz[LINMAX][COLMAX], int linhas, int colunas,int nivel);


void pos_death(int NLinhasMax,int NColunasMax,char matriz[LINMAX][COLMAX],int posicao[2][MAXSNAKE], char *movimento,
               char * possivelmovimento, Tipo_Cont *contador,TIPO_OBJETO *apple,int * size_snake, int nivel, int * vidas );

void inicializa_fase(int nivel, char matriz[LINMAX][COLMAX],int * NLinhasMax, int * NColunasMax,int * nPedras, TIPO_OBJETO pedra[], char * movimento, char *  possivelmovimento,Tipo_Cont * contador,
                     TIPO_OBJETO * apple, int * size_snake, int posicao[2][MAXSNAKE], int vidas, int pontos) ;
#endif // INICIALIZAR_H_INCLUDED
