#ifndef SCORES_H_INCLUDED
#define SCORES_H_INCLUDED
#include "moviment.h"

typedef struct str_score
{
    char nome[25];
    int pontos;
} TIPO_SCORE;

TIPO_SCORE insere_nome(int pontos);

void escreve_scores(FILE * arq, TIPO_SCORE new_scores[]);

void novo_top_15(TIPO_SCORE new_scores[], TIPO_SCORE scores[],TIPO_SCORE new_player);

void load_scores(FILE * arq, TIPO_SCORE scores[]);

void salva_score(int pontos);

void end_game(int pontos);

void le_score();

#endif // SCORES_H_INCLUDED
