#ifndef MENU_GAME_H_INCLUDED
#define MENU_GAME_H_INCLUDED
#include "moviment.h"


void atualiza_caracteres(char tecla, char setas[4]);
void atualiza_seta(char setas_left[4], char setas_right[4], int *selected, int *actual_option);
void imprime_seta(char setas_left[4], char setas_right[4]);
void imprime_arts();
int menu_principal();


#endif // MENU_GAME_H_INCLUDED
