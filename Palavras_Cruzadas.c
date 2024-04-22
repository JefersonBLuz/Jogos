#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define HEIGHT 10
#define WIDTH 15
#define LIMITE 5
int new, scenario, mistakes, correct, number;
char matrix[HEIGHT][WIDTH];
char word[99], correctword = 0;
char *wordsused[10][3] = {                                                                  /*10 palvras, palavra/dica/letras*/
                          {"oculus", "Para usar tem que abrir as pernas", 6},               // 0
                          {"vidro", "Composto pela areia em alta temperatura", 5},          // 1
                          {"oxigenio", "Componente da água que tem 6 eletrons", 8},         // 2
                          {"pangeia", "Continente que era banhado por um uncio oceano", 7}, // 3
                          {"borboleta", "Transformação do lagarta", 9},                     // 4
                          {"caju", "Fruta que tem semente por fora", 4},                    // 5
                          {"acaraje", "Comida tipica da Bahia", 7},                         // 6
                          {"amendoin", "Comida tipica do São João", 8},                     // 7
                          {"rato", "Animal roedor", 4},                                     // 8
                          {"peru", "Animal que sabe o dia da morte", 4}};                   // 9
struct worddraw
{
    int numb;
    int x;
    int y;
    int fuction;
    int letter;
    int code;
} worddraw[5];
void clean()
{
    printf("\e[1;1H\e[2J");
}
int numbrandom()
{
    int random = rand();
    return random % LIMITE;
}
void printmatrix()
{
    printf("┌");
    for (int i = 0; i < WIDTH - 1; i++)
    {
        printf("───┬");
    }
    printf("───┐\n");
    for (int line = 0; line < HEIGHT; line++)
    {
        printf("│");
        for (int column = 0; column < WIDTH; column++)
        {
            if (matrix[line][column] == NULL)
            {
                printf("   │");
            }
            else
            {
                printf(" %c │", matrix[line][column]);
            }
        }
        if (line != HEIGHT - 1)
        {
            printf("\n├");
            for (int i = 0; i < WIDTH - 1; i++)
            {
                printf("───┼");
            }
            printf("───┤\n");
        }
    }
    printf("\n└");
    for (int i = 0; i < WIDTH - 1; i++)
    {
        printf("───┴");
    }
    printf("───┘\n");
}
void changehorizontal(int x, int y, int letter) // 3fuction
{
    for (int i = 0; i < letter; i++)
    {
        if (new)
        {
            matrix[y][x + i] = '*';
        }
        else
        {
            matrix[y][x + i] = word[i];
        }
    }
}
void changevertical(int x, int y, int letter) // 2fuction
{
    for (int i = 0; i < letter; i++)
    {
        if (new)
        {
            matrix[y + i][x] = '*';
        }
        else
        {
            matrix[y + i][x] = word[i];
        }
    }
}
void changediagonal(int x, int y, int letter) // 1fuction
{
    for (int i = 0; i < letter; i++)
    {
        if (new)
        {
            matrix[y + i][x + i] = '*';
        }
        else
        {
            matrix[y + i][x + i] = word[i];
        }
    }
}
void changecaracter(int x, int y, int letter, int fuction)
{
    switch (fuction)
    {
    case 1:
        changediagonal(x, y, letter);
        break;
    case 2:
        changevertical(x, y, letter);
        break;
    case 3:
        changehorizontal(x, y, letter);
        break;
    default:
        break;
    }
}
void newgame()
{
    mistakes = 5;
    correct = 0;
    for (size_t i = 0; i < HEIGHT; i++)
    {
        for (size_t c = 0; c < WIDTH; c++)
        {
            matrix[i][c] = NULL;
        }
    }
    new = 1;
    scenario = numbrandom();
    switch (scenario)
    {
    case 0:
        matrix[0][0] = '1'; // BORBOLETA
        worddraw[1].numb = 4;
        worddraw[1].x = 1;
        worddraw[1].y = 1;
        worddraw[1].fuction = 1;
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[2][1] = '2'; // OCULUS
        worddraw[2].numb = 0;
        worddraw[2].x = 2;
        worddraw[2].y = 2;
        worddraw[2].fuction = 3;
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[3][2] = '3'; // RATO
        worddraw[3].numb = 8;
        worddraw[3].x = 3;
        worddraw[3].y = 3;
        worddraw[3].fuction = 3;
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[9][7] = '4'; // CAJU
        worddraw[4].numb = 5;
        worddraw[4].x = 8;
        worddraw[4].y = 9;
        worddraw[4].fuction = 3;
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;
    case 1:
        matrix[0][7] = '1'; // OXIGENIO
        worddraw[1].numb = 2;
        worddraw[1].x = 7;
        worddraw[1].y = 1;
        worddraw[1].fuction = 2;
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[5][5] = '2'; // PERU
        worddraw[2].numb = 9;
        worddraw[2].x = 6;
        worddraw[2].y = 5;
        worddraw[2].fuction = 3; // HORIZONTAL
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[3][5] = '3'; // VIDRO
        worddraw[3].numb = 1;
        worddraw[3].x = 6;
        worddraw[3].y = 3;
        worddraw[3].fuction = 3; // HORINZONTAL
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[2][10] = '4'; // OCULUS
        worddraw[4].numb = 0;
        worddraw[4].x = 10;
        worddraw[4].y = 3;
        worddraw[4].fuction = 2; // VERTICAL
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;
    case 2:
        matrix[0][4] = '1'; // PANGEIA
        worddraw[1].numb = 3;
        worddraw[1].x = 4;
        worddraw[1].y = 1;
        worddraw[1].fuction = 2; // VERTCIAL
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[3][3] = '2'; // ACARAJE
        worddraw[2].numb = 6;
        worddraw[2].x = 4;
        worddraw[2].y = 3;
        worddraw[2].fuction = 3; // HORIZONTAL
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[8][3] = '3'; // AMENDOIN
        worddraw[3].numb = 2;
        worddraw[3].x = 4;
        worddraw[3].y = 8;
        worddraw[3].fuction = 3; // HORINZONTAL
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[1][6] = '4'; // CAJU
        worddraw[4].numb = 0;
        worddraw[4].x = 6;
        worddraw[4].y = 2;
        worddraw[4].fuction = 2; // VERTICAL
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;
    case 3:
        matrix[0][0] = '1'; // BORBOLETA
        worddraw[1].numb = 4;
        worddraw[1].x = 1;
        worddraw[1].y = 1;
        worddraw[1].fuction = 1;
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[2][1] = '2'; // OCULUS
        worddraw[2].numb = 0;
        worddraw[2].x = 2;
        worddraw[2].y = 2;
        worddraw[2].fuction = 3;
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[3][2] = '3'; // RATO
        worddraw[3].numb = 8;
        worddraw[3].x = 3;
        worddraw[3].y = 3;
        worddraw[3].fuction = 3;
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[9][7] = '4'; // CAJU
        worddraw[4].numb = 5;
        worddraw[4].x = 8;
        worddraw[4].y = 9;
        worddraw[4].fuction = 3;
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;
    case 4:
        matrix[0][7] = '1'; // OXIGENIO
        worddraw[1].numb = 2;
        worddraw[1].x = 7;
        worddraw[1].y = 1;
        worddraw[1].fuction = 2;
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[5][5] = '2'; // PERU
        worddraw[2].numb = 9;
        worddraw[2].x = 6;
        worddraw[2].y = 5;
        worddraw[2].fuction = 3; // HORIZONTAL
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[3][5] = '3'; // VIDRO
        worddraw[3].numb = 1;
        worddraw[3].x = 6;
        worddraw[3].y = 3;
        worddraw[3].fuction = 3; // HORINZONTAL
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[2][10] = '4'; // OCULUS
        worddraw[4].numb = 0;
        worddraw[4].x = 10;
        worddraw[4].y = 3;
        worddraw[4].fuction = 2; // VERTICAL
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;
    case 5:
        matrix[0][4] = '1'; // PANGEIA
        worddraw[1].numb = 3;
        worddraw[1].x = 4;
        worddraw[1].y = 1;
        worddraw[1].fuction = 2; // VERTCIAL
        worddraw[1].letter = wordsused[worddraw[1].numb][2];
        changecaracter(worddraw[1].x, worddraw[1].y, worddraw[1].letter, worddraw[1].fuction);
        matrix[3][3] = '2'; // ACARAJE
        worddraw[2].numb = 6;
        worddraw[2].x = 4;
        worddraw[2].y = 3;
        worddraw[2].fuction = 3; // HORIZONTAL
        worddraw[2].letter = wordsused[worddraw[2].numb][2];
        changecaracter(worddraw[2].x, worddraw[2].y, worddraw[2].letter, worddraw[2].fuction);
        matrix[8][3] = '3'; // AMENDOIN
        worddraw[3].numb = 2;
        worddraw[3].x = 4;
        worddraw[3].y = 8;
        worddraw[3].fuction = 3; // HORINZONTAL
        worddraw[3].letter = wordsused[worddraw[3].numb][2];
        changecaracter(worddraw[3].x, worddraw[3].y, worddraw[3].letter, worddraw[3].fuction);
        matrix[1][6] = '4'; // CAJU
        worddraw[4].numb = 0;
        worddraw[4].x = 6;
        worddraw[4].y = 2;
        worddraw[4].fuction = 2; // VERTICAL
        worddraw[4].letter = wordsused[worddraw[4].numb][2];
        changecaracter(worddraw[4].x, worddraw[4].y, worddraw[4].letter, worddraw[4].fuction);
        break;

    default:
        break;
    }
    new = 0;
}
int main(int argc, char const *argv[])
{
    char confirmation;
    int checknumber = 1, checkchoice = 1;
    printf("Deseja iniciar o jogo de palavras cruzadas?\n(S/N): ");
    scanf(" %c", &confirmation);
    while (confirmation == 'S' || confirmation == 's')
    {
        clean();
        newgame();
        printf("Bem vindo ao jogo de palavras cruzadas!\nCenário sorteado é: %d.\nVocê só tem direito a 5 erros.\n", scenario);
        while (correct < 4 && mistakes > 0)
        {
            printmatrix();
            printf("\nVocê tem %d chances.\nQual número deseja advinhar?\nNúmero: ", mistakes);
            scanf(" %d", &number);
            do
            {
                while (number < 1 || number > 4)
                {
                    printf("\nNúmero invalido, escolha outro número!\nNúmero: ");
                    scanf(" %d", &number);
                }
                checknumber = 0;
                while (worddraw[number].code == 1)
                {
                    printf("\nLocal já preenchido, escolha outro número!\nNúmero: ");
                    scanf(" %d", &number);
                    checknumber = 1;
                }
                checkchoice = 0;
            } while (checknumber || checkchoice);
            printf("Dica: %s\nPalavra: ", wordsused[worddraw[number].numb][1]);
            scanf(" %s[^\n]", word);
            int validation = (strcmp(wordsused[worddraw[number].numb][0], word) == 0);
            if (validation)
            {
                clean();
                printf("Acertou\n");
                changecaracter(worddraw[number].x, worddraw[number].y, worddraw[number].letter, worddraw[number].fuction);
                correct++;
                worddraw[number].code = 1;
            }
            else
            {
                clean();
                printf("Errou!\n");
                mistakes--;
            }
        }
        printmatrix();
        if (correct == 4)
        {
            printf("Parabéns, você completou!");
        }
        else
        {
            printf("Infelizmente você perdeu!");
        }

        printf("\nDeseja jogar novamente ?(S/N)\nR: ");
        scanf(" %c", &confirmation);
    }

    return 0;
}
