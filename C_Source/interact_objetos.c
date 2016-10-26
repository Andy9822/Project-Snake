#include "interact_objetos.h"

///lida com a colisão com a maçã
void check_eat_apple(int posicao[2][MAXSNAKE],TIPO_OBJETO * apple, int * pontos,int * comeu)
{

    if(colisao(posicao,*apple))             ///Se colisionou com maça/a comeu aplica o que é determinado a acontecer pela ação
    {
        *pontos += 10;
        *comeu = 1;
        apple->x = 0;
        apple->y = 0;
        apple->onscreen = 0;

    }

}

///Testa condições de morte do jogador, retorna 1 caso ele esteja morto
int morreu(int posicao[2][MAXSNAKE],char matriz[LINMAX][COLMAX],int NLinhasMax,int NColunasMax,int size_snake)
{
    int retorno = 0, i=0, saida = 0;

    while(i < size_snake  && saida== 0)
    {
        if(posicao[0][0] == posicao[0][i+1] && posicao[1][0] == posicao[1][i+1])  ///Testa se a cabeça esta acima de alguma parte do corpo
            saida = 1;
        i++;
    }


    if( saida == 1 || matriz[posicao[1][0]][posicao[0][0]] == '#' || size_snake < 2)
        retorno = 1;

    return retorno;
}

///Testa se um objeto a ser criado vai ocupar a mesma posição de um pedra, caso sim retorna 1
int in_objeto(TIPO_OBJETO pedras[],int nPedras,TIPO_OBJETO objeto)
{
 int saida = 0, i = 0;

   while(saida ==0 && i<nPedras)
   {
     if(pedras[i].x == objeto.x && pedras[i].y == objeto.y)
     {
        saida = 1;
     }

    i++;

   }

 return saida;
}

///Testa se um objeto a ser criado vai ocupar a mesma posição da snake, caso sim retorna 1
int in_snake(int posicao[][MAXSNAKE],TIPO_OBJETO objeto,int size_snake)
{
 int saida= 0, i=0;

  while(saida==0 && i< size_snake)
  {
    if(posicao[0][i] == objeto.x && posicao[1][i] == objeto.y)
    {
        saida = 1;
    }

    i++;
  }
  return saida;
}

///Testa colisão entre a snake e um TIPO_OBJETO, caso ocupem a mesma posição retorna 1
int colisao(int posicao[][MAXSNAKE],TIPO_OBJETO objeto)
{
    int resposta = 0;
    if(posicao[0][0] == objeto.x && posicao[1][0] == objeto.y)
    {
            resposta = 1;
    }

   return resposta;
}

///Lida com colisões entre a snake e pedras
void check_pedra_hit(int posicao[2][MAXSNAKE],int * size_snake,TIPO_OBJETO pedra[ROCKSMAX], int nPedras, int * pontos)
{
    int flag = 0, i = 0;
    while(i < nPedras && !flag)
    {
      flag = colisao(posicao,pedra[i]);   ///Testa colisao da cobra com cada pedra
      i++;
    }

    if( flag == 1)
    {   goutoxy( posicao[0][*size_snake -1] + KX , posicao[1][*size_snake - 1] + KY );
        printf(" ");                            ///Se houve colisao, diminui 1 tamanho
        *size_snake = *size_snake -1 ;
         if(*pontos > 0)
         {
            *pontos = *pontos -1 ;
         }
    }

}

///Lida com colisões entre a snake e um camundongo
void check_eat_mouse(int posicao[2][MAXSNAKE], int *size_snake, TIPO_OBJETO ratos[RATOSMAX],Tipo_Cont * contador ,int * pontos,int nivel)
{
 int i=0, sair = 0;

  while(sair ==0 && i < contador->ratos_surgidos)   ///Testa enquanto há ratos e nao houver comido algum/colisionado com algum
  {
   if( colisao(posicao,ratos[i]) && ratos[i].onscreen ==1 )
   {
     Beep(550,22);
     *size_snake = *size_snake + 1;
     sair = 1;
     *pontos = *pontos + ( 1 * nivel );
     contador->ratos_comidos +=  1;
     ratos[i].onscreen = 0;
   }

   i++;
  }

}
