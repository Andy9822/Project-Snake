#include "Menu_game.h"
#define YELLOW 14
///Atualiza vetores das setas > <
void atualiza_caracteres(char tecla, char setas[4])
{
  int i;
  char aux;
  if(tecla == 'W')
  {
    aux = setas[0];
    for(i=0; i<3;i++)
     setas[i] = setas[i+1];
    setas[3] = aux;
  }

  else
   { aux = setas[3];
      for(i=3; i>0;i--)
       setas[i] = setas[i-1];
     setas[0] = aux;
   }
}

///Atualiza informaçoes apos apertar pra cima ou pra baixo no menu
void atualiza_seta(char setas_left[4], char setas_right[4], int *selected, int *actual_option)
{
  char tecla = getch();

  ///Se tecla pressionada sao setas direcionais transforma em A ou W
  setas_to_wasd(&tecla);

  switch(toupper(tecla))
  {
    case 'S':

       if(*actual_option != 4)                      ///Se nao eh opçao mais de baixo, vai uma opçao pra baixo
         {
          *actual_option = *actual_option + 1;
         }
       else
         {
           *actual_option = 1;                    ///Se for, vai pra primeira opçao
         }
       atualiza_caracteres(tecla,setas_left);
       atualiza_caracteres(tecla,setas_right);
       break;
     case 'W':                                  ///Se nao eh opçao mais de cima, vai uma opçao pra cima
        if(*actual_option != 1)
         {
           *actual_option = *actual_option - 1;
         }
       else                                     ///Se for, vai pra ultima opçao
         {
          *actual_option = 4;
         }
       atualiza_caracteres(toupper(tecla),setas_left);
       atualiza_caracteres(toupper(tecla),setas_right);
       break;
    case ' ':                                   ///Caso apertar enter, escolha a opção onde  > < estavam apontando
    case 13 :
       *selected = *actual_option;
   }

}

///Imprime as setas > < na opçao da vez no menu
void imprime_seta(char setas_left[4], char setas_right[4])
{
  ///Setas da opçao Jogar Agora
  goutoxy(46,14); printf("%c",setas_left[0]);
  goutoxy(63,14); printf("%c",setas_right[0]);
  ///Setas da opçao Aprender a jogar
  goutoxy(44,16); printf("%c",setas_left[1]);
  goutoxy(65,16); printf("%c",setas_right[1]);
  ///Setas da opçao Ver pontuações Maximas
  goutoxy(44,18); printf("%c",setas_left[2]);
  goutoxy(66,18); printf("%c",setas_right[2]);
  ///Setas da opçao Sair do Jogo
  goutoxy(47,20); printf("%c",setas_left[3]);
  goutoxy(62,20); printf("%c",setas_right[3]);

}

///Imprime arts do menu
void imprime_arts()
{

textcolor(12);printf("\n\n                          ______    ____  _____        _        ___  ____    ________  ");       textcolor(10);printf("     \\--_ ......._-_--.\\ /\n");
textcolor(12);printf("                        .' ____ \\  |_   \\|_   _|      / \\      |_  ||_  _|  |_   __  | ");        textcolor(10);printf("      (|\\ /      / /| \\  \\\n");
textcolor(12);printf("                        | (___ \\_|   |   \\ | |       / _ \\       | |_/ /      | |_ \\_| ");       textcolor(10);printf("      /  /     .'  -=-'   `.\n");
textcolor(12);printf("                         _.____`.    | |\\ \\| |      / ___ \\      |  __.\\      |  _| _  ");       textcolor(10);printf("     /  /    .'             )\n");
textcolor(12);printf("                        | \\____) |  _| |_\\   |_   _/ /   \\ \\_   _| |  \\ \\_   _| |__/ | ");     textcolor(10);printf("   _/  /   .'        _.)   /\n");
textcolor(12);printf("                         \\______.' |_____|\\____| |____| |____| |____||____| |________|");         textcolor(10);printf("   / o   o        _.-' /  .'\n");
                                                  printf("                                                                                         \\          _.-'    / .'*|\n");
                                                  printf("                                                                                          \\______.-'//    .'.' \\*|\n");
                                                 printf("                                                                                           \\|  \\ | //   .'.' _ |*|\n");
                                                  printf("                                                                                            `   \\|//  .'.'_ _ _|*|\n");
textcolor(YELLOW);printf("                       -----------------------------------------------------------------");        textcolor(10);printf("     .  .// .'.' | _ _ \\*|\n");
textcolor(YELLOW);printf("                       |                                                               |");     textcolor(10);printf("     \\`-|\\_/ /    \\ _ _ \\*\\\n");
textcolor(YELLOW);printf("                       |                         JOGAR AGORA !                         |");     textcolor(10);printf("       /'\\__/      \\ _ _ \\*\\\n");
textcolor(YELLOW);printf("                       |                                                               |");     textcolor(10);printf("     /^|            \\ _ _ \\*\n");
textcolor(YELLOW);printf("                       |                       APRENDER A JOGAR                        |");     textcolor(10);printf("    '  `             \\ _ _ \\  \n");
textcolor(YELLOW);printf("                       |                                                               |");             textcolor(10);printf("                      \\_\n");
textcolor(YELLOW);printf("                       |                       VER OS HIGHSCORES                       |\n");
                  printf("                       |                                                               |\n");
                  printf("                       |                         SAIR DO JOGO                          |\n");
                  printf("                       |                                                               |\n");
                  printf("                       -----------------------------------------------------------------");
}

///Chama menu principal
int menu_principal()
{
  int selected = 0, actual_option = 1;
  char setas_left[4] = {'>',' ',' ',' '};
  char setas_right[4] = {'<',' ',' ',' '};

  imprime_arts();
  do
  {
    imprime_seta(setas_left, setas_right);
    esconde_cursor();
    atualiza_seta(setas_left, setas_right,&selected,&actual_option);
  }while(!selected);                                                ///Até nao apertar enter, movimenta apenas as setas > <

  return selected;
}
