#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int greater(char, char);
int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % n;
}

int main()
{
    int player1score = 0, compscore = 0;
    int temp;
    char playerchar, compchar;
    char dict[] = {'r', 'p', 's'};
   

    printf("\n");

    printf(" \t\t\t WELCOM TO ROCK PAPER SCISSOR GAME \t\t\t\n\n");

    for (int i = 1; i <= 3; i++)
    {
        printf(" %d ROUND \n ", i);

        printf("PLAYER 1 :-  Choose your options\n\n");
        printf(" 1. Rock\n");
        printf(" 2. Paper\n");
        printf(" 3. Scissor\n\n");

        scanf("%d", &temp);
        getchar();
        playerchar = dict[temp - 1];

        printf("You have selcted %c\n\n", playerchar);

        printf("Computer :-  Choose your options\n\n");
        printf(" 1. Rock\n");
        printf(" 2. Paper\n");
        printf(" 3. Scissor\n\n");

        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];

        printf(" Computerselcted %c\n\n", compchar);

        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf(" ************** Computer Won the %d Round ************\n\n", i);
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 0;
            player1score += 0;
            printf(" ************** %d Round DRAW ************\n\n", i);
        }
        else
        {
            player1score += 1;
            printf(" ************** You Won the  %d Round! ************\n\n", i);
        }

        printf("\t\t\t\t\t Your Score  :-  %d \t\t Computerscore %d\n\n", player1score, compscore);
    }

    if (player1score > compscore)
    {
        printf(" \t\t\t\t\t\t\t\t  Hurry! You won the game \n");
    }

    else if (compscore > player1score)
    {
        printf("\t\t\t\t\t\t\t\t Bad luck Computer Won the round !\n");
    }

    else
    {
        printf("*********************  Final status Draw  **********************\n");
    }

    return 0;
}

int greater(char char1, char char2)
{
    if (char1 == char2)
    {
        return -1;
    }

    if ((char1 == 'p') && (char2 == 'r'))
    {
        return 1;
    }
    else if ((char2 == 'p') && (char1 == 'r'))
    {
        return 0;
    }

    if ((char1 == 'r') && (char2 == 's'))
    {
        return 1;
    }
    else if ((char2 == 'r') && (char1 == 's'))

    {
        return 0;
    }

    if ((char1 == 's') && (char2 == 'p'))
    {
        return 1;
    }
    else if ((char2 == 's') && (char1 == 'p'))

    {
        return 0;
    }
}