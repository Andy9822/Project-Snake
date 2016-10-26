#include "moviment.h"


///Jogo
void jogando()
{
    system("cls");
    char matriz[LINMAX][COLMAX];
    int size_snake, nivel = 1, nPedras, comeu_maca = 0;
    int posicao[2][MAXSNAKE], NLinhasMax, NColunasMax;
    int  pontos = 0,vidas = 3, pausar = 1;
    Tipo_Cont contador;
    TIPO_OBJETO ratos[RATOSMAX],  pedra[ROCKSMAX];
    TIPO_OBJETO apple = {0,0,0};

    ///Snake começa indo pra direita
    char movimento,possivelmovimento;

    ///HUD
    printa_hud();

    ///Inicia elementos do nivel
    inicializa_fase(nivel,matriz,&NLinhasMax,&NColunasMax,&nPedras,pedra,&movimento,&possivelmovimento,&contador,&apple,&size_snake,posicao,vidas,pontos);

    ///Enquanto nao digitar nada x, segue se mexendo
    while(possivelmovimento != 'Q' && possivelmovimento != 27 && vidas > 0)                     ///Enquanto tiver vidas e nao apertar em tecla pra sair do jogo
    {

        if(kbhit())                                                                           ///Se nao digita nada, seguira mesma direção
        {
            possivelmovimento = getch();
            validaMovimento(&possivelmovimento, &movimento,&pausar);                         ///Confere se a tecla pressionada é um movimento valido

            while(kbhit())
            {
                getch();                                                                    ///  PEGA LETRA MOVIMENTO
            }
        }

        atualizaCobra(posicao, movimento,size_snake);                                       ///Atualiza posiçoes da cobra e verifica colisões com objetos (sem ser paredes)
        check_pedra_hit(posicao,&size_snake,pedra,nPedras,&pontos);                         ///e se for, acontece o que é determinado para cada tipo de colisão
        check_eat_mouse(posicao,&size_snake,ratos,&contador,&pontos,nivel);
        new_movimento(&contador,posicao,NLinhasMax,NColunasMax,ratos,size_snake,pedra,nPedras, matriz,&apple);
        check_eat_apple(posicao,&apple,&pontos,&comeu_maca);

        ///Caso coma a maçã
        if(comeu_maca)
        {
            imprime_cobra(posicao, size_snake,movimento);
            Beep(800,160);
            nivel++;
            if(nivel < NMAX)                                                            ///Se ainda nao tiver passado por todos os niveis segue jogando no prox nivel
            {
                comeu_maca = 0;
                inicializa_fase(nivel,matriz,&NLinhasMax,&NColunasMax,&nPedras,pedra,&movimento,&possivelmovimento,&contador,&apple,&size_snake,posicao,vidas,pontos);
            }
            else
            {
                vidas = 0;                                                               ///Acabaram as fases e acabou o jogo
            }

        }
        else if(!morreu(posicao,matriz,NLinhasMax,NColunasMax,size_snake) )              ///Se nao colisiona com parede ou fica menor que 2 a cobra se movimenta
            {


             atualiza_hud(vidas,pontos,nivel,contador);                                  ///Redesenha a cobra novo lugar, as pedras, atualiza pontos etc...
             redesenha_pedras(pedra,nPedras);
             imprime_cobra(posicao, size_snake,movimento);
             surge_apple(size_snake,posicao,matriz,NColunasMax,NLinhasMax,pedra,ratos,contador.ratos_surgidos,nivel,&apple,nPedras);
             Sleep(260  - (8 * nivel + 0.25 * contador.movimentos) );

            }
            else                                                                          ///Morreu, perde vida e reinicia mapa se ainda tiver vidas
            {
                pos_death(NLinhasMax,NColunasMax,matriz,posicao, &movimento, &possivelmovimento, &contador,&apple, &size_snake, nivel, &vidas );
            }
    }

    system("cls");
    if(vidas == 0)                                                                    ///Se o jogador parou de jogar porque morreu ou virou o jogo
    {
        end_game(pontos);                                                             ///Contabiliza os pontos e ve tabela de Highscores
    }

}
int main()
{

    system("mode con:cols=225 lines=65");
    int exit_game =0;

    do
    {
        system("cls");
        switch(menu_principal())
        {
        case 1:
            jogando();
            break;
        case 2:
            how_play();
            esconde_cursor();
            my_fflush();
            break;
        case 3:
            le_score();
            esconde_cursor();
            my_fflush();
            break;
        case 4:
            exit_game=1;
            goutoxy(0,23);
            break;
        }

    }
    while(!exit_game);

    return 0;
}
