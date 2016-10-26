#include "print.h"
#include <locale.h>
#define WHITE 15
#define GREEN 2
#define YELLOW 14
///Ao morrer a cobra, limpa seu rastro antes de reiniciar mapa ou acabar jogo
void limpa_cobra(int tam, int posicao[2][MAXSNAKE])
{
    int  i;
    for(i = 1; i < tam; i ++ )
    {
        goutoxy( posicao[0][i] + KX, posicao[1][i] + KY );
        printf(" ");
    }
    Beep(500,250);
}

///Imprime cobra na posiçao atual
void imprime_cobra(int posicao[2][MAXSNAKE], int size_snake,char movimento)
{
    int i;
    textcolor(14);
    for(i=0; i<size_snake; i++)
    {
        if (i==0)
        {
            goutoxy( posicao[0][i]+KX,posicao[1][i]+KY);                            ///Trata a nova forma da cabeça dependendo movimento que fez
            switch(movimento)
            {
            case 'A':
                printf(">");
                break;
            case 'D':
                printf("<");
                break;
            case 'W':
                printf("V");
                break;
            default:
                printf("^");
                break;
            }

        }
        else
        {
            goutoxy((posicao[0][i] + KX),(posicao[1][i]+KY));                   ///Trata forma de um pedaço do corpo em relação à parte anterior
            if((posicao[1][i]) == (posicao[1][i-1]))
            {

                printf("-");
            }
            else
            {

                printf("'");
            }

        }

    }

}

///Mostra as instruçoes do jogo
void how_play()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    FILE * arq;
    char linhas[200];
    if( !(arq = fopen("howto.txt","r")))
    {
        perror("Erro ao carregar instruções de jogo\n");
    }
    else
    {
        while(!feof(arq))
        {
            fgets(linhas,200,arq);
            puts(linhas);
        }

    }
 fclose(arq);
}

/// Imprime o Mapa do nivel da vez
void imprime_Mapa(int NLinhasMax, int NColunasMax, char matriz[LINMAX][COLMAX])
{
    int i, j;
    textcolor(11);
    for(i=0; i<NLinhasMax; i++)
    {
        for(j=0; j<NColunasMax; j++)
        {
            goutoxy(KX+j,KY+i);
            printf("%c", matriz[i][j]);
        }

        printf("\n");
    }

}

///Imprime um objeto em tal posiçao
void imprime_objeto(int x_objeto, int y_objeto,char simbolo)
{
    goutoxy(x_objeto + KX,y_objeto+KY);
    printf("%c",simbolo);

}

///Imprime HUD com as infos da jogatina e desenhos em volta da tela do jogo
void printa_hud()
{

    textcolor(WHITE);
    goutoxy(KX - 10,1);
    printf("Vidas =     Pontos =      Nivel =     Camundongos    /");
    goutoxy(0,16);


    textcolor(GREEN);
    printf("           /^\\/^\\ \n");
    textcolor(GREEN);
    printf("          _|__|  O| \n");
    textcolor(GREEN);
    printf(" \\/     /~     \\_/ \\ ");
    textcolor(YELLOW);
    printf("                                    ____  _____________   ____  ____     __________   __ \n");
    textcolor(GREEN);
    printf("  \\____|__________/  \\ ");
    textcolor(YELLOW);
    printf("                                 / / / / / ___/_  __/  / __ \\/ __ \\   /  _/_  __/  / /\n");
    textcolor(GREEN);
    printf("         \\_______      \\ ");
    textcolor(YELLOW);
    printf("                          __  / / / / /\\__ \\ / /    / / / / / / /   / /  / /    / /  \n");
    textcolor(GREEN);
    printf("                 `\\     \\                  \\ ");
    textcolor(YELLOW);
    printf("     / /_/ / /_/ /___/ // /    / /_/ / /_/ /  _/ /  / /    /_/   \n");
    textcolor(GREEN);
    printf("                   |     |                  \\ ");
    textcolor(YELLOW);
    printf("    \\____/\\____//____//_/    /_____/\\____/  /___/ /_/    (_)     \n");
    textcolor(GREEN);
    printf("                  /      /                    \\ \n");
    textcolor(GREEN);
    printf("                 /     /                       \\\\ \n");
    textcolor(GREEN);
    printf("               /      /                         \\ \\ \n");
    textcolor(GREEN);
    printf("              /     /                            \\  \\ \n");
    textcolor(GREEN);
    printf("            /     /             _----_            \\   \\ \n");
    textcolor(GREEN);
    printf("           /     /           _-~      ~-_         |   | \n");
    textcolor(GREEN);
    printf("          (      (        _-~    _--_    ~-_     _/   | \n");
    textcolor(GREEN);
    printf("           \\      ~-____-~    _-~    ~-_    ~-_-~    / \n");
    textcolor(GREEN);
    printf("             ~-_           _-~          ~-_       _-~ \n");
    textcolor(GREEN);
    printf("                ~--______-~                ~-___-~ \n");

}

///Atualiza HUD coom os novos valores de vidas/pontos/nivel/camundongos comidos
void atualiza_hud(int vidas,int pontos, int nivel,Tipo_Cont contador)
{
    textcolor(WHITE);
    goutoxy(43,1);
    printf("%02d",vidas);
    goutoxy(56,1);
    printf("%03d",pontos);
    goutoxy(69,1);
    printf("%02d",nivel);
    goutoxy(86,1);
    printf("%02d",contador.ratos_comidos);
    goutoxy(89,1);
    printf("%02d",contador.n_ratos);

}
