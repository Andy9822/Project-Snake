#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED
#include "moviment.h"

void textcolor(int ForgC);

void pause_game(int * flag);

void my_fflush();

void esconde_cursor();

void goutoxy(int x, int y);

FILE * seletor_fase(int n);

void setas_to_wasd(char*tecla);

#endif // UTILITY_H_INCLUDED
