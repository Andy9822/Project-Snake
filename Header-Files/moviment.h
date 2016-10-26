#ifndef FUNCOES_PROPRIAS_H_INCLUDED
#define FUNCOES_PROPRIAS_H_INCLUDED
#include <stdio.h>
#include <time.h>
#define NMAX 3
#define LINMAX 30
#define COLMAX 30
#define TEMPO_RATO 5
#define RATOSL1 20
#define RATOSL2 45
#define ROCKSMAX 15
#define RATOSMAX 45
#define MAXSNAKE 33
#include "scores.h"
#include "generate.h"
#include "print.h"
#include "tools.h"
#include "Menu_game.h"
#include "interact_objetos.h"
#include <ctype.h>
#include <windows.h>
#include <conio.h>
#include "inicializar.h"



void new_movimento(Tipo_Cont * contador,int posicao[2][MAXSNAKE], int NLinhasMax, int NColunasMax,
                   TIPO_OBJETO ratos[RATOSMAX],int size_snake,TIPO_OBJETO pedra[],int nPedras, char matriz[LINMAX][COLMAX],TIPO_OBJETO * apple);

int contra_mao(char possivelmovimento, char movimento);

void atualizaCobra(int posicao[2][MAXSNAKE], char movimento, int size_snake);

void validaMovimento(char * possivelmovimento, char* movimento,int * flag);

#endif // FUNCOES_PROPRIAS_H_INCLUDED

