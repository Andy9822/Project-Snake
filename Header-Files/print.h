#ifndef PRINT_H_INCLUDED
#define PRINT_H_INCLUDED
#include "moviment.h"


void limpa_cobra(int tam, int posicao[2][MAXSNAKE]);

void imprime_cobra(int posicao[2][MAXSNAKE], int size_snake,char movimento);

void imprime_Mapa(int NLinhasMax, int NColunasMax, char matriz[LINMAX][COLMAX]);

void imprime_objeto(int x_objeto, int y_objeto,char simbolo);

void atualiza_hud(int vidas,int pontos, int nivel,Tipo_Cont contador);

void printa_hud();

void how_play();
#endif // PRINT_H_INCLUDED
