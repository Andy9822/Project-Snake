#include <scores.h>
#include <locale.h>

///Recebe a pontuação do jogador atual, que deve digitar o seu nome, retorna o TIPO_SCORE com o nome e pontuação do jogador
TIPO_SCORE insere_nome(int pontos)
{
    TIPO_SCORE new_player;

    printf("Nome:\n");
    fgets(new_player.nome, 25, stdin);
    new_player.nome[ strlen(new_player.nome) - 1] ='\0'; // tira o \n do enter apos dar enter pois é inserido na string por usar fgets do stdin
    new_player.pontos = pontos;
    return new_player;

}

///Salva o novo arquivo binário de pontuações
void escreve_scores(FILE * arq, TIPO_SCORE new_scores[])
{
    int  i;
    for(i = 0; i < 15; i++)
    {

        if(fwrite(&new_scores[i], sizeof(TIPO_SCORE), 1, arq) != 1)
        {
            printf("Erro ao salvar score");
        }
    }
}

///Compara scores do arquivo binário com o score do novo jogador e modifica o array de scores que será salvo
void novo_top_15(TIPO_SCORE new_scores[], TIPO_SCORE scores[],TIPO_SCORE new_player)
{
    int i, j=0, sair= 0;
    for(i = 0; i < 15; i++)
    {
        if(new_player.pontos > scores[i].pontos && sair == 0)
        {
            new_scores[i] = new_player;
            sair = 1;

        }
        else
        {
            new_scores[i] = scores[j];
            j++;
        }
    }

}

///Carrega arquivo binário de scores
void load_scores(FILE * arq, TIPO_SCORE scores[])
{
    int i;
    for(i = 0; i < 15; i++)
    {
        if(fread(&scores[i], sizeof(TIPO_SCORE), 1, arq) != 1)
        {
            printf("Erro ao carregar score %d \n", i+1);
        }
    }


}

///Host das outras funções ligando com a pontuação e variáveis associadas
void salva_score(int pontos)
{
    FILE * arq;
    TIPO_SCORE old_scores[15];
    TIPO_SCORE new_scores[15];
    TIPO_SCORE new_player;



    if(!(arq = fopen("highscores.bin", "rb+")))
    {
        perror("Erro ao abrir o arquivo highscores.bin");
    }
    else
    {
        load_scores(arq,old_scores);                                    ///Carrega scores antigos, modifica se preciso esse vetor de scores
        new_player = insere_nome(pontos);
        novo_top_15(new_scores,old_scores,new_player);                 ///E escreve de volta novo vetor no arquivo
        rewind(arq);
        escreve_scores(arq,new_scores);
    }
    fclose(arq);

}

///Le arquivo de scores e printa na tela as 15 maiores pontuações
void le_score()
{
    setlocale(LC_ALL, "Portuguese");
    system("cls");
    TIPO_SCORE scores[15];
    FILE * arq;
    int i;

    printf("\n\n\t \t \t \t \t Top 15 pro players scores\n");

    if(!(arq = fopen("highscores.bin", "rb")))
    {
        perror("Erro ao abrir o arquivo highscores.bin");
    }
    else
    {
        for(i = 0; i < 15; i++)
        {
            if( i % 3 == 0 && i != 0 )
                printf("\n");
            if(fread(&scores[i], sizeof(TIPO_SCORE), 1, arq) != 1)
            {
                printf("Erro ao carregar score");
            }
            else
            {
                printf("%25s: %5d ", scores[i].nome, scores[i].pontos);

            }

        }
    }

    printf("\n\n\n\n\t\t\t\t\t\t\t Digite qualquer tecla para voltar ao menu principal... -->\n");
    fclose(arq);

}

///Termina o jogo chama as funções para salvar o score e mostrar os resultados
void end_game(int pontos)
{
    system("cls");
    printf("Voce fez %d pontos!! Parabens!\n", pontos);
    Sleep(1500);
    salva_score(pontos);
    le_score();
    esconde_cursor();
    my_fflush();

}


