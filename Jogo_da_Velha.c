#include <stdio.h>
int matriz[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
char coordenada[3];
int jogadas = 1, playernumber = 0;
void clean()
{
    printf("\e[1;1H\e[2J");
}
struct player
{
    char name[99];
    int win;
} player[2];
void gameold()
{
    printf("     A   B   C  ");
    printf("\n   ╔═══╦═══╦═══╗\n");
    for (size_t i = 0; i < 3; i++)
    {
        printf("%d  ║", i + 1);
        for (size_t c = 0; c < 3; c++)
        {
            if (matriz[i][c] == 0) // 0 é igual a nulo
            {
                printf("   ");
                printf("║");
            }
            else if (matriz[i][c] == 1) // 1 é igual a X
            {
                printf(" X ");
                printf("║");
            }
            else if (matriz[i][c] == 2) // 2 é igaul a O
            {
                printf(" O ");
                printf("║");
            }
        }
        if (i < 2)
        {
            printf("\n   ");
            printf("╠═══╬═══╬═══╣");
        }
        printf("\n");
    }
    printf("   ╚═══╩═══╩═══╝\n");
}
void display()
{
    printf("    JOGO DA VELHA\n");
    for (size_t i = 0; i < 20; i++)
    {
        printf("═");
    }
    printf("\n");
    gameold();
}
void registerplay()
{
    printf("Olá seja bem vindo ao jogo da velha!\n\n");
    for (int i = 0; i < 2; i++)
    {
        printf("Informe o nome do %d° jogador: ", i + 1);
        scanf(" %[^\n]", player[i].name);
    }
}
void newgame()
{
    for (int y = 0; y < 3; y++)
    {
        for (int x = 0; x < 3; x++)
        {
            matriz[x][y] = 0;
        }
    }
    jogadas = 1;
}
int checkletra()
{
    if (coordenada[0] == 'A' || coordenada[0] == 'a')
    {
        coordenada[0] = 0;
        return 0;
    }
    else if (coordenada[0] == 'B' || coordenada[0] == 'b')
    {
        coordenada[0] = 1;
        return 0;
    }
    else if (coordenada[0] == 'C' || coordenada[0] == 'c')
    {
        coordenada[0] = 2;
        return 0;
    }
    else
    {
        clean();
        display();
        printf("\nCoordenada não encontrada!\n");
        return 1;
    }
}
int checknumber()
{
    if (coordenada[1] == '1')
    {
        coordenada[1] = 0;
        return 0;
    }
    else if (coordenada[1] == '2')
    {
        coordenada[1] = 1;
        return 0;
    }
    else if (coordenada[1] == '3')
    {
        coordenada[1] = 2;
        return 0;
    }
    else
    {
        clean();
        display();
        printf("\nCoordenada não encontrada!\n");
        return 1;
    }
}
int checklocal()
{
    int x, y;
    x = coordenada[0];
    y = coordenada[1];
    if (matriz[y][x] != 0)
    {
        clean();
        display();
        printf("\nLocal preenchido informe outro!\n");
        return 1;
    }
    else if (jogadas % 2 == 0)
    {
        matriz[y][x] = 2;
        clean();
        display();
        return 0;
    }
    else if (jogadas % 2 != 0)
    {
        matriz[y][x] = 1;
        clean();
        display();
        return 0;
    }
}
void printmove()
{
    int i;
    clean();
    display();
    do
    {
        printf("É a vez do %s jogar!\nInforme primeiro a letra depois o número. Exemplo: A1.\nInforme a coordenada: \n", player[playernumber].name);
        scanf(" %2[^\n]", coordenada);
    } while (checkletra() || checknumber() || checklocal());
    jogadas++;
}
int checkwin()
{

    if (matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != 0 || /*1ºLinha*/
        matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != 0 || /*2ºLinha*/
        matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != 0 || /*3ºLinha*/
        matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != 0 || /*1ºColuna*/
        matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != 0 || /*2ºColuna*/
        matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != 0 || /*3ºColuna*/
        matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != 0 || /*Diagonal principal*/
        matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0] && matriz[0][2] != 0 /*Diagonal secundaria*/)
    {
        clean();
        display();
        printf("\nJogador %s ganhou ☺ !!\n", player[playernumber].name);
        player[playernumber].win++;
        jogadas = 10;
        if (playernumber)
        {
            playernumber = 0;
        }
        else
        {
            playernumber = 1;
        }
    }
    else if (jogadas == 10)
    {
        printf("\n♦EMPATE♦\nDeu Velha!!");
    }
}
void main()
{
    int numb;
    char valid = 'S';
    clean();
    registerplay();
    clean();
    do
    {
        while (valid == 'S' || valid == 's')
        {
            newgame();
            while (jogadas < 10)
            {
                printmove();
                checkwin();
                if (playernumber)
                {
                    playernumber = 0;
                }
                else
                {
                    playernumber = 1;
                }
            }
            printf("\nFim de jogo!!\n\nDeseja jogar novamente?\n(S/N)\n");
            scanf(" %1[^\n]", &valid);
        }
        if (player[0].win == player[1].win)
        {
            printf("Infelizmente ninguém foi campeão :/\nAmbos ganharam %d vezes!\nDesejam desempatar?(S/N)\n");
            scanf(" %1[^\n]", &valid);
        }
        else if (player[0].win > player[1].win)
        {
            printf("Jogador campeão é %s com %d número(s) de vitória!", player[0].name, player[0].win);
            printf("\nJogador Vice campeão é %s com %d número(s) de vitória!", player[1].name, player[1].win);
        }
        else
        {
            printf("Jogador campeão é %s com %d número(s) de vitória!", player[1].name, player[1].win);
            printf("\nJogador Vice campeão é %s com %d número(s) de vitória!", player[0].name, player[0].win);
        }

    } while (valid == 'S' || valid == 's');
}
