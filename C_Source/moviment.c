#include "moviment.h"

///Conta quantos movimentos a cobra faz, e a cada X gera um camundongo ou o apaga
void new_movimento(Tipo_Cont * contador,int posicao[2][MAXSNAKE], int NLinhasMax, int NColunasMax,TIPO_OBJETO ratos[RATOSMAX],
                   int size_snake,TIPO_OBJETO pedras[],int nPedras, char matriz[LINMAX][COLMAX],TIPO_OBJETO * apple)
{
  ///A cada N movimentos (mov % n == 0)  e enquanto houver ratos por surgir, faz surgir mais um rato
  if(contador->movimentos % (TEMPO_RATO + NColunasMax/7) == 0 && contador->ratos_surgidos < contador->n_ratos)
  {
    gera_rato(posicao,NLinhasMax,NColunasMax, &(ratos[contador->ratos_surgidos]) ,size_snake,pedras,nPedras, matriz,apple);
    contador->ratos_surgidos = contador->ratos_surgidos + 1;
  }

  /// (So começa a deletar depois do primeiro rato que surge)       A cada 4n movimentos (mov % 4n == 0) deleta o ratog erado caso nao tenha sido comido
  if( contador->movimentos >= ( (TEMPO_RATO + NColunasMax/7) * 4) && (contador->movimentos % (TEMPO_RATO + NColunasMax/7) == 0) )
  {
      if( ratos[contador->rato_a_deletar].onscreen == 1)            ///Se rato ainda tiver na tela, apaga ele
      {
        goutoxy(ratos[contador->rato_a_deletar].x + KX, ratos[contador->rato_a_deletar].y + KY);
        printf(" ");
        ratos[contador->rato_a_deletar].onscreen = 0;
      }
    contador->rato_a_deletar = contador->rato_a_deletar + 1;
  }
  contador->movimentos+= 1;


}

///Verifica se a cobra tenta ir pra direçao oposta à que vinha
int contra_mao(char possivelmovimento, char movimento)
{
   int retorno = 0;

   if( (possivelmovimento =='A' && movimento =='D') || (possivelmovimento =='D' && movimento =='A')
     ||(possivelmovimento =='S' && movimento =='W') || (possivelmovimento =='W' && movimento =='S'))
     retorno = 1;

 return retorno;
}

///Atualiza posiçao da cobra
void atualizaCobra(int posicao[2][MAXSNAKE], char movimento, int size_snake)
{
    ///Cauda da cobra some porque ela mudou de posiçao              Ultima parte do corpo assumiu a proxima posiçao, precisa apagar rastro na matriz mapa
    goutoxy((posicao[0][size_snake-1] + KX),(posicao[1][size_snake-1] + KY));
    printf(" ");

    ///Atualiza partes da cobra
    int j;
    for(j=size_snake;j>0;j--)
    {   posicao[0][j] = posicao[0][j-1];                         /* Troca o valor de X da posicao tal, com o da anterior à dela */
        posicao[1][j] = posicao[1][j-1];                         /* Troca o valor de Y da posicao tal, com o valor y da posicao anterior*/
    }
    switch (movimento)                                           /*Ve qual foi o movimento daquela vez  */
    {   ///Atualiza cabeça cobra
        case 'A' :
        case 37 :
            posicao[0][0] =  posicao[0][0] - 1;                      /* Se inserir A vai pra esquerda, logo diminui 1 do valor X */
            break;
        case 'S' :
        case 40 :
            posicao[1][0] = posicao[1][0] + 1;                       /* Se inserir S vai para baixo, logo aumenta 1 o valor de y pois pra baixo é 1 valor a mais da matriz */
            break;
        case 'D' :
        case 39 :
            posicao[0][0] = posicao[0][0] + 1;                       /* Se inserir D vai pra direita, logo aumenta 1 do valor X */
            break;
        case 'W' :
        case 38 :
            posicao[1][0] = posicao[1][0] - 1;                       /* Se inserir W vai para cima, logo diminui 1 o valor de y pois pra cima é 1 valor a menos da matriz */
            break;
    }

}

///Determina se o char inserido como direção para movimento da cobra é válido (se for seta transforma em wasd correspondente)
void validaMovimento(char * possivelmovimento, char * movimento,int * flag)
{

    setas_to_wasd(possivelmovimento);
    *possivelmovimento = toupper(*possivelmovimento);

    ///So entende que é novo movimento se for alguma das teclas WASD e nao for sentido contrario
    if ((*possivelmovimento=='A'||*possivelmovimento=='S'||*possivelmovimento=='D'||*possivelmovimento=='W') && !contra_mao(*possivelmovimento,*movimento))
    {
        *movimento = *possivelmovimento;
    }

    ///Se a letra for P usuario queria pausar game
    if (*possivelmovimento == 'P')
        pause_game(flag);
}


