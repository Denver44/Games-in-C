#include <stdio.h>
#include <stdlib.h>

char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
void show();
void gamename();
void inputsymbol();
void start();
void play();
void check(char, char);
int end();
int count = 0;
int main()

{
    int decision;
    char wish;
label1:
    system("CLS"); 
    gamename();
    show();
    inputsymbol();
    start();
    play();
label:
    system("CLS");
    show();
    play();
    decision = end();
    system("CLS");
    show();

    if (count < 9)
    {

        if (decision == 100)
        {
            printf("Player1 won the game\n");
            count = 0;
        }
        else if (decision == 200)
        {
            printf("Player2 won the game\n");
            count = 0;
        }
        else
            goto label;
    }

    else
    {
        printf("\n **************** GAME DRAW *********************\n");
        count = 0;
    }
    printf("\nDo you wish to restart the game 'Y' for Yes & 'N' for No\n");
    getchar();
    scanf("%c", &wish);
    if (wish == 'y' || wish == 'Y')
    {
        a[0] = '1';
        a[1] = '2';
        a[2] = '3';
        a[3] = '4';
        a[4] = '5';
        a[5] = '6';
        a[6] = '7';
        a[7] = '8';
        a[8] = '9';
        goto label1;
    }

    else if (wish == 'n' || wish == 'N')
    {
        printf("\n\n ****************** THANK YOU FOR PLAYING THE GAME *****************************************\n");
    }

    return 0;
}
void gamename()
{
    printf("\n\n\t\t\tWELCOME TO TIC TAC TOE GAME\n\n");
}
void show()
{
    printf("\n\t\t\t\t    |    |   \n");
    printf("\t\t\t\t %c  | %c  |  %c\n", a[0], a[1], a[2]);
    printf("\t\t\t\t    |    |   \n");
    printf("\t\t\t\t %c  | %c  |  %c\n", a[3], a[4], a[5]);
    printf("\t\t\t\t    |    |   \n");
    printf("\t\t\t\t %c  | %c  |  %c\n", a[6], a[7], a[8]);
    printf("\n\n");
}
void inputsymbol()
{
    printf("PLAYER 1 SYMBOL :-  X\n");
    printf("PLAYER 2 SYMBOL :-  0\n");
}
void start()
{
    int p;
    printf("\nEnter who will start the game Player 1 or Player 2\n");
    scanf("%d", &p);
    if (p == 1)
    {
        printf("\nPlayer1 turn's\n");
    }
    else
        printf("Player2 turn's\n\n");
}

void play()
{

    char p, s;
    printf("Enter the position and symbol where u want to put your symbol\n");
    getchar();
    scanf("%c", &p);
    getchar();
    scanf("%c", &s);
    count++;
    check(p, s);
}

void check(char P, char S)
{
    int i;
    for (i = 0; i <= 8; i++)
    {
        if (a[i] == P)
        {
            a[i] = S;
        }
    }
}

int end()
{
    if ((a[0] == 'x' && a[1] == 'x' && a[2] == 'x') || (a[3] == 'x' && a[4] == 'x' && a[5] == 'x') || (a[6] == 'x' && a[7] == 'x' && a[8] == 'x'))
    {
        return 100;
    }
    else if ((a[0] == 'x' && a[3] == 'x' && a[6] == 'x') || (a[1] == 'x' && a[4] == 'x' && a[7] == 'x') || (a[2] == 'x' && a[5] == 'x' && a[8] == 'x'))
    {
        return 100;
    }

    else if ((a[0] == 'x' && a[4] == 'x' && a[8] == 'x') || (a[2] == 'x' && a[4] == 'x' && a[6] == 'x'))
    {
        return 100;
    }

    else if ((a[0] == 'X' && a[1] == 'X' && a[2] == 'X') || (a[3] == 'X' && a[4] == 'X' && a[5] == 'X') || (a[6] == 'X' && a[7] == 'X' && a[8] == 'X'))
    {
        return 100;
    }
    else if ((a[0] == 'X' && a[3] == 'X' && a[6] == 'X') || (a[1] == 'X' && a[4] == 'X' && a[7] == 'X') || (a[2] == 'X' && a[5] == 'X' && a[8] == 'X'))
    {
        return 100;
    }

    else if ((a[0] == 'X' && a[4] == 'X' && a[8] == 'X') || (a[2] == 'X' && a[4] == 'X' && a[6] == 'X'))
    {
        return 100;
    }

    else if ((a[0] == '0' && a[1] == '0' && a[2] == '0') || (a[3] == '0' && a[4] == '0' && a[5] == '0') || (a[6] == '0' && a[7] == '0' && a[8] == '0'))
    {
        return 200;
    }
    else if ((a[0] == '0' && a[3] == '0' && a[6] == '0') || (a[1] == '0' && a[4] == '0' && a[7] == '0') || (a[2] == '0' && a[5] == '0' && a[8] == '0'))
    {
        return 200;
    }

    else if ((a[0] == '0' && a[4] == '0' && a[8] == '0') || (a[2] == '0' && a[4] == '0' && a[6] == '0'))
    {
        return 200;
    }

    return 300;
}