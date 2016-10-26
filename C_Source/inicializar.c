#include "moviment.h"

///Inicializa as variáveis necessárias para começar um novo jogo
void start_snake(char * movimento, char * possivelmovimento, Tipo_Cont * contador,TIPO_OBJETO * apple, int * size_snake,
                 int posicao[2][MAXSNAKE], char matriz[LINMAX][COLMAX], int linhas, int colunas,int nivel)
{
    contador->movimentos = (TEMPO_RATO + colunas/7) - 1;
    contador->n_ratos = 0;
    contador->rato_a_deletar = 0;
    contador->ratos_surgidos = 0;
    contador->ratos_comidos = 0;
    apple->onscreen = 0;
    apple->x = 0;
    apple->y = 0;
    *movimento = 'D';
    *possivelmovimento ='A';
    *size_snake = 2;

    Nratos_atual(nivel, contador );
    new_snake(posicao,matriz,linhas,colunas);

}

///Executa operações necessárias após o jogador morrer IE: limpar a tela e reduzir total de vidas
void pos_death(int NLinhasMax,int NColunasMax,char matriz[LINMAX][COLMAX],int posicao[2][MAXSNAKE], char *movimento, char * possivelmovimento, Tipo_Cont *contador,TIPO_OBJETO *apple,
               int * size_snake, int nivel, int * vidas )
{
    *vidas -=1;
    contador->ratos_comidos = 0;
    if(*vidas>0)
    {
        limpa_cobra(*size_snake,posicao);
        imprime_Mapa(NLinhasMax, NColunasMax, matriz);
        start_snake(movimento, possivelmovimento, contador,apple, size_snake, posicao, matriz, NLinhasMax,NColunasMax,nivel);
    }
}

///Executa funções de inicio de fase
void inicializa_fase(int nivel, char matriz[LINMAX][COLMAX],int * NLinhasMax, int * NColunasMax,int * nPedras, TIPO_OBJETO pedra[], char * movimento, char *  possivelmovimento,Tipo_Cont * contador,
                     TIPO_OBJETO * apple, int * size_snake, int posicao[2][MAXSNAKE], int vidas, int pontos)
{
    ///Gerador do mapa
    cria_fase(nivel,matriz,NLinhasMax,NColunasMax);
    imprime_Mapa(*NLinhasMax,*NColunasMax,matriz);

    ///Gerador de possiveis objetos do nivel
    *nPedras = conta_objetos(matriz,*NLinhasMax,*NColunasMax,'*');
    inicia_objeto(matriz,*NLinhasMax,*NColunasMax,pedra,'*');

    ///Inicia Snake-Game
    start_snake(movimento, possivelmovimento, contador, apple, size_snake, posicao, matriz, *NLinhasMax,*NColunasMax,nivel);
    atualiza_hud(vidas,pontos,nivel,*contador);

}
