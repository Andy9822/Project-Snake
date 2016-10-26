#include "tools.h"

///Função para a coloração do texto
void textcolor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

    return;
}

///Pausa o jogo
void pause_game(int * flag)
{
    char saida;
    *flag += 1;
    if(*flag % 2 == 0)
    {
        do
        {
            esconde_cursor();
            saida = toupper(getch());
            *flag = 1;
        }
        while(saida!= 'P');

    }

}

///Para quando apertar tecla pra sair da funçao esconde_cursor e a tecla nao ser interpretada por função futura
void my_fflush()
{
 char aux;
 aux = getch();         ///Limpar buffer do teclado para o menu_principal() nao pegar uma tecla de uma funçao passada que usasse !kbhit
 aux +=1;               ///Operar com a variavel apenas para nao dar warning de variavel nao sendo utilizada
}

///Esconder cursor para nao piscar tela
void esconde_cursor()
{
    while(!kbhit())
    {
        goutoxy(48,21);
        printf("%c",' ');
        Sleep(100);
    }

}

///Definir posicao cursor (funcao gotoxy da conio que, gotoxy da conio2 dava eventuais bugs)
void goutoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}

///Dependendo do nivel, carrega o mapa correspondente desde o arquivo de texto
FILE * seletor_fase(int n)
{
    FILE * arquivo;
    switch(n)
    {
    case 1:
        arquivo = fopen("mapa1.txt", "r");
        break;

    case 2:
        arquivo = fopen("mapa2.txt", "r");
        break;

    }
    return arquivo;
}

///Transforma entrada em seta em correspondente WASD
void setas_to_wasd(char*tecla)
{
    if(*tecla == -32)
    {
        *tecla =getch();
        switch(*tecla)
        {
        case 72 :
            *tecla = 'W';
            break;
        case 80 :
            *tecla = 'S';
            break;
        case 77:
            *tecla = 'D';
            break;
        case 75 :
            *tecla = 'A';
            break;
        }

    }

}
