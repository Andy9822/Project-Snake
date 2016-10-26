#ifndef INTERACT_OBJETOS_H_INCLUDED
#define INTERACT_OBJETOS_H_INCLUDED

#include "moviment.h"

void check_eat_apple(int posicao[2][MAXSNAKE],TIPO_OBJETO * apple, int * pontos,int * comeu);

int morreu(int posicao[2][MAXSNAKE],char matriz[LINMAX][COLMAX],int NLinhasMax,int NColunasMax,int size_snake);

int colisao(int posicao[][MAXSNAKE],TIPO_OBJETO objeto);

void check_eat_mouse(int posicao[2][MAXSNAKE], int *size_snake, TIPO_OBJETO ratos[RATOSMAX],Tipo_Cont *contador , int * pontos, int nivel);

int in_snake(int posicao[][MAXSNAKE],TIPO_OBJETO objeto,int size_snake);

void check_pedra_hit(int posicao[2][MAXSNAKE],int * size_snake,TIPO_OBJETO pedra[ROCKSMAX], int nPedras, int * pontos);

int in_objeto(TIPO_OBJETO pedras[],int nPedras,TIPO_OBJETO objeto);

#endif // INTERACT_OBJETOS_H_INCLUDED
